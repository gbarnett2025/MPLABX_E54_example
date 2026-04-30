#include "definitions.h" // includes system headers, declares STATE_GOOD if configured
#include "FreeRTOS.h"
#include "task.h"

//#define STATE_GOOD_PIN    PIO_PIN_PA16
//#define STATE_PWR_PIN    PIO_PIN_PA23

void vUart0Task(void *pvParameters)
{
    const char msg[] = "UART0 test!\r\n";
    UART0_Write((uint8_t*)msg, sizeof(msg) - 1);

    uint8_t ch;
    while (1)
    {
        // Block until a character is received
        if (UART0_Read(&ch, 1))
            UART0_Write(&ch, 1); // Echo back to Tera Term
    }
}