/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "FreeRTOS.h"
#include <string.h> 
#include "task.h"
#include "queue.h"

#define UART_RX_QUEUE_LENGTH  128
QueueHandle_t uartRxQueue;
uint8_t rxByteGlobal;             // RX buffer for incoming byte

TaskHandle_t xLED_Tasks;
TaskHandle_t xUART_Tasks;
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
void LED_Task ( void *pvParameters )
{
    while(1)
    {
        LED_Toggle();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
//void UART_Task ( void )
//{
//    // cntrl + shift + C for block comment uncomment
////    char *buffer = "Hello, World\n";
////    while(1)
////    {
////        SERCOM0_USART_Write( buffer, strlen(buffer) );
////        vTaskDelay(1000 / portTICK_PERIOD_MS);
////    }
//    
//    uint8_t rxByte;
//
//    while (1)
//    {
//        // Blocking read: waits until a byte is received
//        if (SERCOM0_USART_Read(&rxByte, 1)) // Returns true if successful
//        {
//            // Echo back the received byte
//            SERCOM0_USART_Write(&rxByte, 1);
//        }
//        // Optional: Add small delay or handle other logic here
//        vTaskDelay(1); // small delay to yield, prevents tight loop
//    }
//}

void UART_Task(void *pvParameters)
{
    uint8_t rxByte;

    for (;;)
    {
        // Block on the queue, waiting for received byte
        if (xQueueReceive(uartRxQueue, &rxByte, portMAX_DELAY) == pdPASS)
        {
            // Echo received byte
            // Echo back the received byte
            while (!SERCOM0_USART_Write(&rxByte, 1))
                vTaskDelay(pdMS_TO_TICKS(1));       // Not strictly necessary on Harmony, but safest if busy
        }
    }
}

//void SERCOM0_USART_ReadCallback(uintptr_t context)
//{
//    uint8_t rxByte;
//
//    // Read the received byte (API may vary by Harmony version)
//    if (SERCOM0_USART_Read(&rxByte, 1)) //SERCOM0_USART_ReadByte(); // This reads one byte from SERCOM0
//    {
//        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//        xQueueSendFromISR(uartRxQueue, &rxByte, &xHigherPriorityTaskWoken);
//    }
//    portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // Ensure context switch if needed
//}

void SERCOM0_USART_ReadCallback(uintptr_t context)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // 1. IMMEDIATELY start RX for next byte!
    SERCOM0_USART_Read(&rxByteGlobal, 1);

    // 2. Then give the *previous* byte to your RTOS code
    xQueueSendFromISR(uartRxQueue, &rxByteGlobal, &xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    uartRxQueue = xQueueCreate(UART_RX_QUEUE_LENGTH, sizeof(uint8_t));
    SERCOM0_USART_ReadCallbackRegister(SERCOM0_USART_ReadCallback, 0);
    SERCOM0_USART_Read(&rxByteGlobal, 1); // do this to get ball rolling
    //SERCOM0_USART_ReceiveEnable(); // Enable receiver if not already done
        /* Maintain state machines of all polled MPLAB Harmony modules. */
    (void) xTaskCreate(
       (TaskFunction_t) LED_Task,
       "LED_Task",
       1024,
       NULL,
       1U ,
       &xLED_Tasks);

    (void) xTaskCreate(
       (TaskFunction_t) UART_Task,
       "UART_Task",
       1024,
       NULL,
       1U ,
       &xUART_Tasks);
    
    vTaskStartScheduler();    // Start the scheduler, never returns

    // Should never get here
    while (1);  // Optional, defensive

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

