
/*******************************************************************************
  HW GPIO Source File

  File Name:
    HWgpio.c

  Summary:
    This file contains the Hardware control of GPIO pins.

  Description:
    
 *******************************************************************************/
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "FreeRTOS.h"
#include <string.h> 
void toggleHeartbeat(void)
{
    LED_Toggle();
}

void setGpio(uint8_t port,uint8_t pin, uint8_t state )
{
    if (state == 0)
    {
        PORT_REGS->GROUP[port].PORT_OUTCLR  = 1 << pin; // Set pin low 
    }
    else
    {
        PORT_REGS->GROUP[port].PORT_OUTSET = 1 << pin; // Set pin high 
    }
}