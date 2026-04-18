/*******************************************************************************
  UartTask Source File

  File Name:
    UartTask.c

  Summary:
    This file contains the UART task and related functions.

  Description:
    
 *******************************************************************************/
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "FreeRTOS.h"
#include <string.h> 
#include "task.h"
#include "queue.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>   // for va_list, va_start, va_end
#include "HWgpio.h"

TaskHandle_t xUART_Tasks;
uint8_t rxByteGlobal;             // RX buffer for incoming byte
QueueHandle_t uartRxQueue;

uint8_t uartRxByte;
#define UART_RX_BUFFER_SIZE 128
char uartRxLine[UART_RX_BUFFER_SIZE];
volatile uint16_t uartRxIndex = 0;

char firmwareVersion[] = "0.0.1";

// Internal static buffer for the response
static char responseBuffer[UART_RX_BUFFER_SIZE];

void UART_Task(void *pvParameters);

typedef struct {
    const char *name;
    uint8_t port; // 0 PA, 1 PB etc.
    uint16_t pin; // pin within poert 
} GpioControlMap;

static const GpioControlMap ledTable[] = {
    { "led1",    3,  10 }, // EXT3 pin 7 Active low PD10
    { "led2",    3,  11 },  // EXT3 pin 8 Active low PD11
    { "led3",    2,  10 },  // EXT3 pin 6 Active low PC10
};
// to use table 
//PORT_REGS->GROUP[0].PORT_OUTSET = 1 << 7; // Set PA07 high
//PORT_REGS->GROUP[0].PORT_OUTCLR = 1 << 7; // Set PA07 low

void makeUartTask(void)
{
    (void) xTaskCreate(
       (TaskFunction_t) UART_Task,
       "UART_Task",
       2024,
       NULL,
       1U ,
       &xUART_Tasks);
}
void writeUart0(char* message)
{
    //SERCOM0_USART_Write(message, sizeof(message));
    size_t len = strlen(message);
    for ( int offset=0; offset<len; offset++)
    {
        while (!SERCOM0_USART_Write(&message[offset], 1))
                vTaskDelay(pdMS_TO_TICKS(1)); 
    } 
}

// Convert a string to lowercase in-place
static void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void commandParse(const char *input)
{
    char buffer[UART_RX_BUFFER_SIZE];
    strncpy(buffer, input, UART_RX_BUFFER_SIZE - 1);
    buffer[UART_RX_BUFFER_SIZE - 1] = '\0';  // Ensure null-termination

    to_lowercase(buffer);
    writeUart0("In commandParse\r\n");
    writeUart0(buffer);
    writeUart0("\r\n");
    
    // Tokenize the command
    char *token = strtok(buffer, " \t\r\n");
    char *argv[10];
    int argc = 0;

    while (token != NULL && argc < 10) 
    {
        argv[argc++] = token;
        token = strtok(NULL, " \t\r\n");
    }

    // Clear response
    responseBuffer[0] = '\0';
    //snprintf(responseBuffer, sizeof(responseBuffer), "In commandParse \r\n");
    //writeUart0(responseBuffer);                
    //snprintf(responseBuffer, sizeof(responseBuffer), "SUCCESS LED %s:%s", argv[1], argv[2]);
                    
    // Handle "led" command
    // format led <name> on|off
    if (argc == 3 && strcmp(argv[0], "led") == 0) 
    {
        // Match LED name
        for (size_t i = 0; i < sizeof(ledTable) / sizeof(GpioControlMap); i++) 
        {
            if (strcmp(argv[1], ledTable[i].name) == 0) 
            {
                uint8_t state;
                if (strcmp(argv[2], "on") == 0) 
                {
                    state = 1;
                } 
                else if (strcmp(argv[2], "off") == 0) 
                {
                    state = 0;
                } else 
                {
                    snprintf(responseBuffer, sizeof(responseBuffer), "ERROR LED action: %s\r\n", argv[2]);
                    writeUart0(responseBuffer); 
                    return;
                    //return responseBuffer;
                }
                
                setGpio(ledTable[i].port,ledTable[i].pin, state );
//                if (state == 0)
//                {
//                    PORT_REGS->GROUP[ledTable[i].port].PORT_OUTCLR  = 1 << ledTable[i].pin; // Set pin low 
//                }
//                else
//                {
//                    PORT_REGS->GROUP[ledTable[i].port].PORT_OUTSET = 1 << ledTable[i].pin; // Set pin high 
//                }
                snprintf(responseBuffer, sizeof(responseBuffer), "SUCCESS LED %s:%s\r\n", argv[1], argv[2]);
                writeUart0(responseBuffer); 
                return;
                //return responseBuffer;
            }
        }

        snprintf(responseBuffer, sizeof(responseBuffer), "ERROR LED %s\r\n", argv[1]);
        writeUart0(responseBuffer); 
        return;
        //return responseBuffer;
    }
    else if (argc == 1 && strcmp(argv[0], "help") == 0)
	{
        writeUart0("Commands:\r\n");
		writeUart0("  FWVER\r\n");
		writeUart0("  HELP\r\n");
		writeUart0("  LED led1|led2|led3 ON|OFF\r\n");
        return;
    }
    
    snprintf(responseBuffer, sizeof(responseBuffer), "ERROR Unknown command\r\n");
    writeUart0(responseBuffer); 
    
}
void UART_Task(void *pvParameters)
{
    uint8_t rxByte;
    
    writeUart0("Start UART0 task\r\n");
    
    for (;;)
    {
        // Block on the queue, waiting for received byte
        if (xQueueReceive(uartRxQueue, &rxByte, portMAX_DELAY) == pdPASS)
        {
            // Echo received byte
            // Echo back the received byte
            while (!SERCOM0_USART_Write(&rxByte, 1))
                vTaskDelay(pdMS_TO_TICKS(1));       // Not strictly necessary on Harmony, but safest if busy
            
            uartRxByte = rxByte;
            if (uartRxByte == '\r' || uartRxIndex >= UART_RX_BUFFER_SIZE - 1) 
            {
                uartRxLine[uartRxIndex] = '\0';  // Null-terminate
                uartRxIndex = 0;
                commandParse(uartRxLine);
            }
            else 
            {
                uartRxLine[uartRxIndex++] = uartRxByte;
            }
        }
            
    }
}

void SERCOM0_USART_ReadCallback(uintptr_t context)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // 1. IMMEDIATELY start RX for next byte!
    SERCOM0_USART_Read(&rxByteGlobal, 1);

    // 2. Then give the *previous* byte to your RTOS code
    xQueueSendFromISR(uartRxQueue, &rxByteGlobal, &xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
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