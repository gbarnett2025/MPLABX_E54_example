/*******************************************************************************
  app_start Source File

  File Name:
    app_start.c

  Summary:
    This file contains the starting point called from main.

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

#include "UartTask.h"
#include "projDef.h"
#include "ledTask.h"
#include "UartHW.h"
#include "HWgeneral.h"


void appStart(void)
{
        /* Initialize all modules */
    HW_Initialization();
    //SYS_Initialize ( NULL );
    uartRxQueue = xQueueCreate(UART_RX_QUEUE_LENGTH, sizeof(uint8_t));
    setUart0ReadCallbackBridge();
    uart0ReadBridge( &rxByteGlobal, 1);
    //SERCOM0_USART_ReadCallbackRegister(SERCOM0_USART_ReadCallback, 0);
    //SERCOM0_USART_Read(&rxByteGlobal, 1); // do this to get ball rolling
    
    
    
    
    //SERCOM0_USART_ReceiveEnable(); // Enable receiver if not already done
        /* Maintain state machines of all polled MPLAB Harmony modules. */
    
    makeLedTask();
    makeUartTask();
    
    vTaskStartScheduler();    // Start the scheduler, never returns

    // Should never get here
    while (1)  // Optional, defensive
    {
        vTaskDelay(1);
    }
    
}