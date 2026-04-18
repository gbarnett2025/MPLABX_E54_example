/*******************************************************************************
  LedTask Source File

  File Name:
    LedTask.c

  Summary:
    This file contains the Led task and related functions.

  Description:
    
 *******************************************************************************/
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "FreeRTOS.h"
#include <string.h> 
#include "HWgpio.h"
TaskHandle_t xLED_Tasks;
void LED_Task ( void *pvParameters );
void makeLedTask(void)
{
    (void) xTaskCreate(
       (TaskFunction_t) LED_Task,
       "LED_Task",
       1024,
       NULL,
       1U ,
       &xLED_Tasks);
}
void LED_Task ( void *pvParameters )
{
    while(1)
    {
        //LED_Toggle();
        toggleHeartbeat();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}