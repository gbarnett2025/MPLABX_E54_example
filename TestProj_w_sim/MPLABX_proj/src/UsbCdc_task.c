#include "usb/usb_device_cdc.h"
#include "usb/usb_device.h"
#include "definitions.h"
#include <string.h>

//extern USB_DEVICE_HANDLE appData.deviceHandle;

void USB_CDC_Task(void *pvParameters)
{
    static const char *cdcMessages[3] = {
        "Hello from CDC Port 1\r\n",
        "Hello from CDC Port 2\r\n"
        "Hello from CDC Port 3\r\n"
    };
    //USB_DEVICE_HANDLE usbDeviceHandle = USB_DEVICE_HANDLE_INVALID;
    USB_DEVICE_CDC_INDEX cdcPort;
    USB_DEVICE_CDC_RESULT result;
    bool configured = false;
    
    //vTaskDelay(pdMS_TO_TICKS(4000));
    
    while (1)
    {
        // Wait until the device is configured by the host PC
        if (0)//USB_DEVICE_StateGet(usbDeviceHandle ) == USB_DEVICE_STATE_CONFIGURED) // need to get the handle to be able to use
        {
            if (!configured)
            {
                configured = true;
                // Send on all 3 CDC instances (adjust if not exactly 3)
                for (cdcPort = 0; cdcPort < 3; cdcPort++)
                {
                    USB_DEVICE_CDC_Write(cdcPort, NULL, (void*)cdcMessages[cdcPort],
                        strlen(cdcMessages[cdcPort]), USB_DEVICE_CDC_TRANSFER_FLAGS_DATA_COMPLETE);
                }
            }
        }
        else
        {
            configured = false; // Reset if device is not configured
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}