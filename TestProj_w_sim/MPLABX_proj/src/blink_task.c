#include "definitions.h" // includes system headers, declares STATE_GOOD if configured
#include "FreeRTOS.h"
#include "task.h"

//#define STATE_GOOD_PIN    PIO_PIN_PA16
//#define STATE_PWR_PIN    PIO_PIN_PA23

void vBlinkTask(void *pvParameters)
{
    PIO_PinSet(LED_PWR_PIN);
    
    while (1)
    {
        // Set PA16 High (LED ON)
        PIO_PinSet(LED_STATE_PIN);
        vTaskDelay(pdMS_TO_TICKS(500));

        // Set PA16 Low (LED OFF)
        PIO_PinClear(LED_STATE_PIN);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}