/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * ... (license text omitted for length) ...
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

 /*-----------------------------------------------------------
  * Application specific definitions.
  * These parameters are described within the 'CONFIGURATION' section of
  * the FreeRTOS API documentation. See https://www.FreeRTOS.org/a00110.html
  *----------------------------------------------------------*/

#define configUSE_PREEMPTION                    1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#define configUSE_IDLE_HOOK                     1
#define configUSE_TICK_HOOK                     1
#define configUSE_DAEMON_TASK_STARTUP_HOOK      1
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )
#define configMINIMAL_STACK_SIZE                ( ( unsigned short ) 512 )
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 49 * 1024 ) )
#define configMAX_TASK_NAME_LEN                 ( 12 )
#define configUSE_TRACE_FACILITY                0
#define configIDLE_SHOULD_YIELD                 1
#define configUSE_MUTEXES                       1
#define configCHECK_FOR_STACK_OVERFLOW          1
#define configUSE_RECURSIVE_MUTEXES             1
#define configQUEUE_REGISTRY_SIZE               20
#define configUSE_MALLOC_FAILED_HOOK            1
#define configUSE_APPLICATION_TASK_TAG          1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_ALTERNATIVE_API               0
#define configUSE_QUEUE_SETS                    1
#define configUSE_TASK_NOTIFICATIONS            1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES   5
#define configSUPPORT_STATIC_ALLOCATION         1
#define configINITIAL_TICK_COUNT                ( ( TickType_t ) 0 )
#define configSTREAM_BUFFER_TRIGGER_LEVEL_TEST_MARGIN 1

#ifdef _M_X64
#define configTICK_TYPE_WIDTH_IN_BITS           TICK_TYPE_WIDTH_64_BITS
#else
#define configTICK_TYPE_WIDTH_IN_BITS           TICK_TYPE_WIDTH_32_BITS
#endif

  /* Software timer related configuration options. */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH                20
#define configTIMER_TASK_STACK_DEPTH            ( configMINIMAL_STACK_SIZE * 2 )

#define configMAX_PRIORITIES                    ( 7 )

/* Run time stats gathering configuration options. */
#define configRUN_TIME_COUNTER_TYPE             uint64_t
#define configGENERATE_RUN_TIME_STATS           0
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() vConfigureTimerForRunTimeStats()
#define portGET_RUN_TIME_COUNTER_VALUE()        ulGetRunTimeCounterValue()

/* Co-routine related configuration options. */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )

#define configUSE_STATS_FORMATTING_FUNCTIONS    0

/* API function inclusion options. */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           0
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_uxTaskGetStackHighWaterMark     1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle  1
#define INCLUDE_xTaskGetIdleTaskHandle          1
#define INCLUDE_xTaskGetHandle                  1
#define INCLUDE_eTaskGetState                   1
#define INCLUDE_xSemaphoreGetMutexHolder        1
#define INCLUDE_xTimerPendFunctionCall          1
#define INCLUDE_xTaskAbortDelay                 1

#if defined( _MSC_VER )
void vAssertCalled( unsigned long ulLine, const char * const pcFileName );
#define configASSERT( x )    if( ( x ) == 0 ) { vAssertCalled( __LINE__, __FILE__ ); }
#endif

#define configINCLUDE_MESSAGE_BUFFER_AMP_DEMO   0
#if ( configINCLUDE_MESSAGE_BUFFER_AMP_DEMO == 1 )
extern void vGenerateCoreBInterrupt(void* xUpdatedMessageBuffer);
#define sbSEND_COMPLETED( pxStreamBuffer ) vGenerateCoreBInterrupt( pxStreamBuffer )
#endif

#ifdef WIN32_LEAN_AND_MEAN
#include "winsock2.h"
#else
#include <winsock.h>
#endif


#endif /* FREERTOS_CONFIG_H */