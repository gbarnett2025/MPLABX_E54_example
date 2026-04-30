

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "FreeRTOS.h"
#include <string.h> 
#include "task.h"
#include "queue.h"

#include "UartTask.h"
#include "queue.h"

void setUart0ReadCallbackBridge(void)
{
    SERCOM0_USART_ReadCallbackRegister(SERCOM0_USART_ReadCallback, 0);
}

bool uart0ReadBridge( void *buffer, const size_t size )
{
    return SERCOM0_USART_Read(buffer, size);
}

bool uart0WriteBridge( void *buffer, const size_t size )
{
    return SERCOM0_USART_Write( buffer, size );
}