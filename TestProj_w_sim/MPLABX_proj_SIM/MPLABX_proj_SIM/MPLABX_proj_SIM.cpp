// MPLABX_proj_SIM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FreeRTOS.h"
#include "task.h"

extern "C" {
    void mainTasks(void);
}
extern "C" void vConfigureTimerForRunTimeStats(void) { /* ... */ }
extern "C" void vApplicationIdleHook(void) { /* ... */ }
extern "C" void vApplicationTickHook(void) { /* ... */ }
extern "C" void vApplicationMallocFailedHook(void) { /* ... */ }
extern "C" void vApplicationStackOverflowHook(TaskHandle_t, char*) { /* ... */ }
extern "C" uint64_t ulGetRunTimeCounterValue(void) { return 0; } // or your implementation

int main()
{
    std::cout << "Hello World!\n";
    mainTasks();
}


