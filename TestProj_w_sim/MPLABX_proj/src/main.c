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

//#include <stddef.h>                     // Defines NULL
//#include <stdbool.h>                    // Defines true
//#include <stdlib.h>                     // Defines EXIT_FAILURE
//#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
//
//int main ( void )
//{
//    /* Initialize all modules */
//    SYS_Initialize ( NULL );
//
//    while ( true )
//    {
//        /* Maintain state machines of all polled MPLAB Harmony modules. */
//        SYS_Tasks ( );
//    }
//
//    /* Execution should not come here during normal operation */
//
//    return ( EXIT_FAILURE );
//}
#include "definitions.h"
//#include "FreeRTOS.h"
//#include "task.h"

//extern void vBlinkTask(void *);
extern void mainTasks(void);
// main function - not used in simulator
int main(void)
{
    // System Initialization
    //SYS_Initialize(NULL);

    mainTasks();
    // Create the Blink Task
    //xTaskCreate(vBlinkTask, "BlinkTask", 128, NULL, 1, NULL);

    // Start the scheduler
    //vTaskStartScheduler();

    // Loop forever if scheduler fails
    while (1);
}

/*******************************************************************************
 End of File
*/

