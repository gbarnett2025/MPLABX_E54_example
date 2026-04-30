/*******************************************************************************
  PIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.h

  Summary:
    PIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (PIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_PIO_H
#define PLIB_PIO_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for SOLENOID7 pin ***/
#define SOLENOID7_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<0U))
#define SOLENOID7_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<0U))
#define SOLENOID7_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<0U))
#define SOLENOID7_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<0U))
#define SOLENOID7_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<0U))
#define SOLENOID7_Get()               ((PIOD_REGS->PIO_PDSR >> 0U) & 0x1U)
#define SOLENOID7_PIN                  PIO_PIN_PD0

/*** Macros for MPU_USB_DET pin ***/
#define MPU_USB_DET_Set()               (PIOE_REGS->PIO_SODR = ((uint32_t)1U<<2U))
#define MPU_USB_DET_Clear()             (PIOE_REGS->PIO_CODR = ((uint32_t)1U<<2U))
#define MPU_USB_DET_Toggle()            (PIOE_REGS->PIO_ODSR ^= ((uint32_t)1U<<2U))
#define MPU_USB_DET_OutputEnable()      (PIOE_REGS->PIO_OER = ((uint32_t)1U<<2U))
#define MPU_USB_DET_InputEnable()       (PIOE_REGS->PIO_ODR = ((uint32_t)1U<<2U))
#define MPU_USB_DET_Get()               ((PIOE_REGS->PIO_PDSR >> 2U) & 0x1U)
#define MPU_USB_DET_PIN                  PIO_PIN_PE2

/*** Macros for MOTOR2_ENA pin ***/
#define MOTOR2_ENA_Set()               (PIOE_REGS->PIO_SODR = ((uint32_t)1U<<3U))
#define MOTOR2_ENA_Clear()             (PIOE_REGS->PIO_CODR = ((uint32_t)1U<<3U))
#define MOTOR2_ENA_Toggle()            (PIOE_REGS->PIO_ODSR ^= ((uint32_t)1U<<3U))
#define MOTOR2_ENA_OutputEnable()      (PIOE_REGS->PIO_OER = ((uint32_t)1U<<3U))
#define MOTOR2_ENA_InputEnable()       (PIOE_REGS->PIO_ODR = ((uint32_t)1U<<3U))
#define MOTOR2_ENA_Get()               ((PIOE_REGS->PIO_PDSR >> 3U) & 0x1U)
#define MOTOR2_ENA_PIN                  PIO_PIN_PE3

/*** Macros for MOTOR2_REFL pin ***/
#define MOTOR2_REFL_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<0U))
#define MOTOR2_REFL_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<0U))
#define MOTOR2_REFL_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<0U))
#define MOTOR2_REFL_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<0U))
#define MOTOR2_REFL_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<0U))
#define MOTOR2_REFL_Get()               ((PIOC_REGS->PIO_PDSR >> 0U) & 0x1U)
#define MOTOR2_REFL_PIN                  PIO_PIN_PC0

/*** Macros for MOTOR1_ENA pin ***/
#define MOTOR1_ENA_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<31U))
#define MOTOR1_ENA_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<31U))
#define MOTOR1_ENA_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<31U))
#define MOTOR1_ENA_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<31U))
#define MOTOR1_ENA_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<31U))
#define MOTOR1_ENA_Get()               ((PIOC_REGS->PIO_PDSR >> 31U) & 0x1U)
#define MOTOR1_ENA_PIN                  PIO_PIN_PC31

/*** Macros for MOTOR2_REFR pin ***/
#define MOTOR2_REFR_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<30U))
#define MOTOR2_REFR_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<30U))
#define MOTOR2_REFR_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<30U))
#define MOTOR2_REFR_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<30U))
#define MOTOR2_REFR_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<30U))
#define MOTOR2_REFR_Get()               ((PIOC_REGS->PIO_PDSR >> 30U) & 0x1U)
#define MOTOR2_REFR_PIN                  PIO_PIN_PC30

/*** Macros for MOTOR1_REFR pin ***/
#define MOTOR1_REFR_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<12U))
#define MOTOR1_REFR_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<12U))
#define MOTOR1_REFR_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<12U))
#define MOTOR1_REFR_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<12U))
#define MOTOR1_REFR_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<12U))
#define MOTOR1_REFR_Get()               ((PIOC_REGS->PIO_PDSR >> 12U) & 0x1U)
#define MOTOR1_REFR_PIN                  PIO_PIN_PC12

/*** Macros for Shut_DIR pin ***/
#define Shut_DIR_Set()               (PIOB_REGS->PIO_SODR = ((uint32_t)1U<<1U))
#define Shut_DIR_Clear()             (PIOB_REGS->PIO_CODR = ((uint32_t)1U<<1U))
#define Shut_DIR_Toggle()            (PIOB_REGS->PIO_ODSR ^= ((uint32_t)1U<<1U))
#define Shut_DIR_OutputEnable()      (PIOB_REGS->PIO_OER = ((uint32_t)1U<<1U))
#define Shut_DIR_InputEnable()       (PIOB_REGS->PIO_ODR = ((uint32_t)1U<<1U))
#define Shut_DIR_Get()               ((PIOB_REGS->PIO_PDSR >> 1U) & 0x1U)
#define Shut_DIR_PIN                  PIO_PIN_PB1

/*** Macros for SOLENOID6 pin ***/
#define SOLENOID6_Set()               (PIOB_REGS->PIO_SODR = ((uint32_t)1U<<0U))
#define SOLENOID6_Clear()             (PIOB_REGS->PIO_CODR = ((uint32_t)1U<<0U))
#define SOLENOID6_Toggle()            (PIOB_REGS->PIO_ODSR ^= ((uint32_t)1U<<0U))
#define SOLENOID6_OutputEnable()      (PIOB_REGS->PIO_OER = ((uint32_t)1U<<0U))
#define SOLENOID6_InputEnable()       (PIOB_REGS->PIO_ODR = ((uint32_t)1U<<0U))
#define SOLENOID6_Get()               ((PIOB_REGS->PIO_PDSR >> 0U) & 0x1U)
#define SOLENOID6_PIN                  PIO_PIN_PB0

/*** Macros for SOLENOID5 pin ***/
#define SOLENOID5_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<20U))
#define SOLENOID5_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<20U))
#define SOLENOID5_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<20U))
#define SOLENOID5_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<20U))
#define SOLENOID5_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<20U))
#define SOLENOID5_Get()               ((PIOA_REGS->PIO_PDSR >> 20U) & 0x1U)
#define SOLENOID5_PIN                  PIO_PIN_PA20

/*** Macros for SOLENOID4 pin ***/
#define SOLENOID4_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<19U))
#define SOLENOID4_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<19U))
#define SOLENOID4_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<19U))
#define SOLENOID4_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<19U))
#define SOLENOID4_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<19U))
#define SOLENOID4_Get()               ((PIOA_REGS->PIO_PDSR >> 19U) & 0x1U)
#define SOLENOID4_PIN                  PIO_PIN_PA19

/*** Macros for SOLENOID3 pin ***/
#define SOLENOID3_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<18U))
#define SOLENOID3_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<18U))
#define SOLENOID3_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<18U))
#define SOLENOID3_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<18U))
#define SOLENOID3_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<18U))
#define SOLENOID3_Get()               ((PIOA_REGS->PIO_PDSR >> 18U) & 0x1U)
#define SOLENOID3_PIN                  PIO_PIN_PA18

/*** Macros for SOLENOID2 pin ***/
#define SOLENOID2_Set()               (PIOB_REGS->PIO_SODR = ((uint32_t)1U<<2U))
#define SOLENOID2_Clear()             (PIOB_REGS->PIO_CODR = ((uint32_t)1U<<2U))
#define SOLENOID2_Toggle()            (PIOB_REGS->PIO_ODSR ^= ((uint32_t)1U<<2U))
#define SOLENOID2_OutputEnable()      (PIOB_REGS->PIO_OER = ((uint32_t)1U<<2U))
#define SOLENOID2_InputEnable()       (PIOB_REGS->PIO_ODR = ((uint32_t)1U<<2U))
#define SOLENOID2_Get()               ((PIOB_REGS->PIO_PDSR >> 2U) & 0x1U)
#define SOLENOID2_PIN                  PIO_PIN_PB2

/*** Macros for SOLENOID1 pin ***/
#define SOLENOID1_Set()               (PIOE_REGS->PIO_SODR = ((uint32_t)1U<<4U))
#define SOLENOID1_Clear()             (PIOE_REGS->PIO_CODR = ((uint32_t)1U<<4U))
#define SOLENOID1_Toggle()            (PIOE_REGS->PIO_ODSR ^= ((uint32_t)1U<<4U))
#define SOLENOID1_OutputEnable()      (PIOE_REGS->PIO_OER = ((uint32_t)1U<<4U))
#define SOLENOID1_InputEnable()       (PIOE_REGS->PIO_ODR = ((uint32_t)1U<<4U))
#define SOLENOID1_Get()               ((PIOE_REGS->PIO_PDSR >> 4U) & 0x1U)
#define SOLENOID1_PIN                  PIO_PIN_PE4

/*** Macros for SOLENOID8 pin ***/
#define SOLENOID8_Set()               (PIOE_REGS->PIO_SODR = ((uint32_t)1U<<5U))
#define SOLENOID8_Clear()             (PIOE_REGS->PIO_CODR = ((uint32_t)1U<<5U))
#define SOLENOID8_Toggle()            (PIOE_REGS->PIO_ODSR ^= ((uint32_t)1U<<5U))
#define SOLENOID8_OutputEnable()      (PIOE_REGS->PIO_OER = ((uint32_t)1U<<5U))
#define SOLENOID8_InputEnable()       (PIOE_REGS->PIO_ODR = ((uint32_t)1U<<5U))
#define SOLENOID8_Get()               ((PIOE_REGS->PIO_PDSR >> 5U) & 0x1U)
#define SOLENOID8_PIN                  PIO_PIN_PE5

/*** Macros for SNS_20 pin ***/
#define SNS_20_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<1U))
#define SNS_20_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<1U))
#define SNS_20_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<1U))
#define SNS_20_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<1U))
#define SNS_20_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<1U))
#define SNS_20_Get()               ((PIOC_REGS->PIO_PDSR >> 1U) & 0x1U)
#define SNS_20_PIN                  PIO_PIN_PC1

/*** Macros for SNS_10 pin ***/
#define SNS_10_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<2U))
#define SNS_10_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<2U))
#define SNS_10_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<2U))
#define SNS_10_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<2U))
#define SNS_10_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<2U))
#define SNS_10_Get()               ((PIOC_REGS->PIO_PDSR >> 2U) & 0x1U)
#define SNS_10_PIN                  PIO_PIN_PC2

/*** Macros for SNS_19 pin ***/
#define SNS_19_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<3U))
#define SNS_19_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<3U))
#define SNS_19_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<3U))
#define SNS_19_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<3U))
#define SNS_19_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<3U))
#define SNS_19_Get()               ((PIOC_REGS->PIO_PDSR >> 3U) & 0x1U)
#define SNS_19_PIN                  PIO_PIN_PC3

/*** Macros for SNS_9 pin ***/
#define SNS_9_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<4U))
#define SNS_9_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<4U))
#define SNS_9_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<4U))
#define SNS_9_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<4U))
#define SNS_9_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<4U))
#define SNS_9_Get()               ((PIOC_REGS->PIO_PDSR >> 4U) & 0x1U)
#define SNS_9_PIN                  PIO_PIN_PC4

/*** Macros for LED_STATE pin ***/
#define LED_STATE_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<16U))
#define LED_STATE_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<16U))
#define LED_STATE_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<16U))
#define LED_STATE_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<16U))
#define LED_STATE_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<16U))
#define LED_STATE_Get()               ((PIOA_REGS->PIO_PDSR >> 16U) & 0x1U)
#define LED_STATE_PIN                  PIO_PIN_PA16

/*** Macros for LED_PWR pin ***/
#define LED_PWR_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<23U))
#define LED_PWR_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<23U))
#define LED_PWR_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<23U))
#define LED_PWR_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<23U))
#define LED_PWR_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<23U))
#define LED_PWR_Get()               ((PIOA_REGS->PIO_PDSR >> 23U) & 0x1U)
#define LED_PWR_PIN                  PIO_PIN_PA23

/*** Macros for SNS_18 pin ***/
#define SNS_18_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<7U))
#define SNS_18_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<7U))
#define SNS_18_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<7U))
#define SNS_18_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<7U))
#define SNS_18_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<7U))
#define SNS_18_Get()               ((PIOC_REGS->PIO_PDSR >> 7U) & 0x1U)
#define SNS_18_PIN                  PIO_PIN_PC7

/*** Macros for LP_FG pin ***/
#define LP_FG_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<15U))
#define LP_FG_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<15U))
#define LP_FG_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<15U))
#define LP_FG_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<15U))
#define LP_FG_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<15U))
#define LP_FG_Get()               ((PIOA_REGS->PIO_PDSR >> 15U) & 0x1U)
#define LP_FG_PIN                  PIO_PIN_PA15

/*** Macros for SNS_17 pin ***/
#define SNS_17_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<6U))
#define SNS_17_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<6U))
#define SNS_17_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<6U))
#define SNS_17_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<6U))
#define SNS_17_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<6U))
#define SNS_17_Get()               ((PIOC_REGS->PIO_PDSR >> 6U) & 0x1U)
#define SNS_17_PIN                  PIO_PIN_PC6

/*** Macros for SNS_8 pin ***/
#define SNS_8_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<5U))
#define SNS_8_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<5U))
#define SNS_8_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<5U))
#define SNS_8_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<5U))
#define SNS_8_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<5U))
#define SNS_8_Get()               ((PIOC_REGS->PIO_PDSR >> 5U) & 0x1U)
#define SNS_8_PIN                  PIO_PIN_PC5

/*** Macros for VACUUM_PWM pin ***/
#define VACUUM_PWM_Get()               ((PIOA_REGS->PIO_PDSR >> 25U) & 0x1U)
#define VACUUM_PWM_PIN                  PIO_PIN_PA25

/*** Macros for MOTOR4_REFR pin ***/
#define MOTOR4_REFR_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<26U))
#define MOTOR4_REFR_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<26U))
#define MOTOR4_REFR_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<26U))
#define MOTOR4_REFR_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<26U))
#define MOTOR4_REFR_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<26U))
#define MOTOR4_REFR_Get()               ((PIOA_REGS->PIO_PDSR >> 26U) & 0x1U)
#define MOTOR4_REFR_PIN                  PIO_PIN_PA26

/*** Macros for LED3 pin ***/
#define LED3_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<19U))
#define LED3_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<19U))
#define LED3_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<19U))
#define LED3_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<19U))
#define LED3_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<19U))
#define LED3_Get()               ((PIOD_REGS->PIO_PDSR >> 19U) & 0x1U)
#define LED3_PIN                  PIO_PIN_PD19

/*** Macros for SPI0_LATCH pin ***/
#define SPI0_LATCH_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<18U))
#define SPI0_LATCH_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<18U))
#define SPI0_LATCH_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<18U))
#define SPI0_LATCH_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<18U))
#define SPI0_LATCH_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<18U))
#define SPI0_LATCH_Get()               ((PIOD_REGS->PIO_PDSR >> 18U) & 0x1U)
#define SPI0_LATCH_PIN                  PIO_PIN_PD18

/*** Macros for MOTOR4_REFL pin ***/
#define MOTOR4_REFL_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<27U))
#define MOTOR4_REFL_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<27U))
#define MOTOR4_REFL_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<27U))
#define MOTOR4_REFL_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<27U))
#define MOTOR4_REFL_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<27U))
#define MOTOR4_REFL_Get()               ((PIOA_REGS->PIO_PDSR >> 27U) & 0x1U)
#define MOTOR4_REFL_PIN                  PIO_PIN_PA27

/*** Macros for SPI0_RESET pin ***/
#define SPI0_RESET_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<17U))
#define SPI0_RESET_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<17U))
#define SPI0_RESET_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<17U))
#define SPI0_RESET_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<17U))
#define SPI0_RESET_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<17U))
#define SPI0_RESET_Get()               ((PIOD_REGS->PIO_PDSR >> 17U) & 0x1U)
#define SPI0_RESET_PIN                  PIO_PIN_PD17

/*** Macros for SNS_7 pin ***/
#define SNS_7_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<8U))
#define SNS_7_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<8U))
#define SNS_7_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<8U))
#define SNS_7_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<8U))
#define SNS_7_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<8U))
#define SNS_7_Get()               ((PIOC_REGS->PIO_PDSR >> 8U) & 0x1U)
#define SNS_7_PIN                  PIO_PIN_PC8

/*** Macros for MOTOR2_CS pin ***/
#define MOTOR2_CS_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<14U))
#define MOTOR2_CS_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<14U))
#define MOTOR2_CS_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<14U))
#define MOTOR2_CS_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<14U))
#define MOTOR2_CS_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<14U))
#define MOTOR2_CS_Get()               ((PIOD_REGS->PIO_PDSR >> 14U) & 0x1U)
#define MOTOR2_CS_PIN                  PIO_PIN_PD14

/*** Macros for SNS_16 pin ***/
#define SNS_16_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<9U))
#define SNS_16_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<9U))
#define SNS_16_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<9U))
#define SNS_16_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<9U))
#define SNS_16_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<9U))
#define SNS_16_Get()               ((PIOC_REGS->PIO_PDSR >> 9U) & 0x1U)
#define SNS_16_PIN                  PIO_PIN_PC9

/*** Macros for MOTOR3_CS pin ***/
#define MOTOR3_CS_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<13U))
#define MOTOR3_CS_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<13U))
#define MOTOR3_CS_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<13U))
#define MOTOR3_CS_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<13U))
#define MOTOR3_CS_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<13U))
#define MOTOR3_CS_Get()               ((PIOD_REGS->PIO_PDSR >> 13U) & 0x1U)
#define MOTOR3_CS_PIN                  PIO_PIN_PD13

/*** Macros for SNS_6 pin ***/
#define SNS_6_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<10U))
#define SNS_6_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<10U))
#define SNS_6_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<10U))
#define SNS_6_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<10U))
#define SNS_6_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<10U))
#define SNS_6_Get()               ((PIOC_REGS->PIO_PDSR >> 10U) & 0x1U)
#define SNS_6_PIN                  PIO_PIN_PC10

/*** Macros for MOTOR4_CS pin ***/
#define MOTOR4_CS_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<12U))
#define MOTOR4_CS_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<12U))
#define MOTOR4_CS_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<12U))
#define MOTOR4_CS_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<12U))
#define MOTOR4_CS_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<12U))
#define MOTOR4_CS_Get()               ((PIOD_REGS->PIO_PDSR >> 12U) & 0x1U)
#define MOTOR4_CS_PIN                  PIO_PIN_PD12

/*** Macros for MOTOR3_ENA pin ***/
#define MOTOR3_ENA_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<2U))
#define MOTOR3_ENA_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<2U))
#define MOTOR3_ENA_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<2U))
#define MOTOR3_ENA_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<2U))
#define MOTOR3_ENA_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<2U))
#define MOTOR3_ENA_Get()               ((PIOA_REGS->PIO_PDSR >> 2U) & 0x1U)
#define MOTOR3_ENA_PIN                  PIO_PIN_PA2

/*** Macros for SNS_15 pin ***/
#define SNS_15_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<11U))
#define SNS_15_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<11U))
#define SNS_15_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<11U))
#define SNS_15_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<11U))
#define SNS_15_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<11U))
#define SNS_15_Get()               ((PIOC_REGS->PIO_PDSR >> 11U) & 0x1U)
#define SNS_15_PIN                  PIO_PIN_PC11

/*** Macros for SNS_5 pin ***/
#define SNS_5_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<14U))
#define SNS_5_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<14U))
#define SNS_5_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<14U))
#define SNS_5_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<14U))
#define SNS_5_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<14U))
#define SNS_5_Get()               ((PIOC_REGS->PIO_PDSR >> 14U) & 0x1U)
#define SNS_5_PIN                  PIO_PIN_PC14

/*** Macros for MOTOR1_REFL pin ***/
#define MOTOR1_REFL_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<11U))
#define MOTOR1_REFL_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<11U))
#define MOTOR1_REFL_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<11U))
#define MOTOR1_REFL_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<11U))
#define MOTOR1_REFL_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<11U))
#define MOTOR1_REFL_Get()               ((PIOD_REGS->PIO_PDSR >> 11U) & 0x1U)
#define MOTOR1_REFL_PIN                  PIO_PIN_PD11

/*** Macros for MOTOR3_REFL pin ***/
#define MOTOR3_REFL_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<1U))
#define MOTOR3_REFL_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<1U))
#define MOTOR3_REFL_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<1U))
#define MOTOR3_REFL_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<1U))
#define MOTOR3_REFL_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<1U))
#define MOTOR3_REFL_Get()               ((PIOA_REGS->PIO_PDSR >> 1U) & 0x1U)
#define MOTOR3_REFL_PIN                  PIO_PIN_PA1

/*** Macros for SNS_14 pin ***/
#define SNS_14_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<16U))
#define SNS_14_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<16U))
#define SNS_14_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<16U))
#define SNS_14_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<16U))
#define SNS_14_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<16U))
#define SNS_14_Get()               ((PIOC_REGS->PIO_PDSR >> 16U) & 0x1U)
#define SNS_14_PIN                  PIO_PIN_PC16

/*** Macros for MOTO3_REFR pin ***/
#define MOTO3_REFR_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<0U))
#define MOTO3_REFR_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<0U))
#define MOTO3_REFR_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<0U))
#define MOTO3_REFR_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<0U))
#define MOTO3_REFR_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<0U))
#define MOTO3_REFR_Get()               ((PIOA_REGS->PIO_PDSR >> 0U) & 0x1U)
#define MOTO3_REFR_PIN                  PIO_PIN_PA0

/*** Macros for SNS_4 pin ***/
#define SNS_4_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<17U))
#define SNS_4_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<17U))
#define SNS_4_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<17U))
#define SNS_4_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<17U))
#define SNS_4_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<17U))
#define SNS_4_Get()               ((PIOC_REGS->PIO_PDSR >> 17U) & 0x1U)
#define SNS_4_PIN                  PIO_PIN_PC17

/*** Macros for SNS_2 pin ***/
#define SNS_2_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<18U))
#define SNS_2_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<18U))
#define SNS_2_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<18U))
#define SNS_2_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<18U))
#define SNS_2_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<18U))
#define SNS_2_Get()               ((PIOC_REGS->PIO_PDSR >> 18U) & 0x1U)
#define SNS_2_PIN                  PIO_PIN_PC18

/*** Macros for MOTOR4_ENA pin ***/
#define MOTOR4_ENA_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<28U))
#define MOTOR4_ENA_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<28U))
#define MOTOR4_ENA_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<28U))
#define MOTOR4_ENA_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<28U))
#define MOTOR4_ENA_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<28U))
#define MOTOR4_ENA_Get()               ((PIOA_REGS->PIO_PDSR >> 28U) & 0x1U)
#define MOTOR4_ENA_PIN                  PIO_PIN_PA28

/*** Macros for LPB_ENA pin ***/
#define LPB_ENA_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<8U))
#define LPB_ENA_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<8U))
#define LPB_ENA_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<8U))
#define LPB_ENA_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<8U))
#define LPB_ENA_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<8U))
#define LPB_ENA_Get()               ((PIOD_REGS->PIO_PDSR >> 8U) & 0x1U)
#define LPB_ENA_PIN                  PIO_PIN_PD8

/*** Macros for MOT_16MHZ pin ***/
#define MOT_16MHZ_Get()               ((PIOA_REGS->PIO_PDSR >> 6U) & 0x1U)
#define MOT_16MHZ_PIN                  PIO_PIN_PA6

/*** Macros for PUMP3 pin ***/
#define PUMP3_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<30U))
#define PUMP3_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<30U))
#define PUMP3_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<30U))
#define PUMP3_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<30U))
#define PUMP3_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<30U))
#define PUMP3_Get()               ((PIOA_REGS->PIO_PDSR >> 30U) & 0x1U)
#define PUMP3_PIN                  PIO_PIN_PA30

/*** Macros for SNS_11 pin ***/
#define SNS_11_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<19U))
#define SNS_11_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<19U))
#define SNS_11_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<19U))
#define SNS_11_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<19U))
#define SNS_11_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<19U))
#define SNS_11_Get()               ((PIOC_REGS->PIO_PDSR >> 19U) & 0x1U)
#define SNS_11_PIN                  PIO_PIN_PC19

/*** Macros for LED5 pin ***/
#define LED5_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<7U))
#define LED5_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<7U))
#define LED5_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<7U))
#define LED5_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<7U))
#define LED5_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<7U))
#define LED5_Get()               ((PIOD_REGS->PIO_PDSR >> 7U) & 0x1U)
#define LED5_PIN                  PIO_PIN_PD7

/*** Macros for SNS_1 pin ***/
#define SNS_1_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<20U))
#define SNS_1_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<20U))
#define SNS_1_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<20U))
#define SNS_1_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<20U))
#define SNS_1_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<20U))
#define SNS_1_Get()               ((PIOC_REGS->PIO_PDSR >> 20U) & 0x1U)
#define SNS_1_PIN                  PIO_PIN_PC20

/*** Macros for LED2 pin ***/
#define LED2_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<6U))
#define LED2_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<6U))
#define LED2_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<6U))
#define LED2_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<6U))
#define LED2_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<6U))
#define LED2_Get()               ((PIOD_REGS->PIO_PDSR >> 6U) & 0x1U)
#define LED2_PIN                  PIO_PIN_PD6

/*** Macros for SNS_12 pin ***/
#define SNS_12_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<21U))
#define SNS_12_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<21U))
#define SNS_12_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<21U))
#define SNS_12_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<21U))
#define SNS_12_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<21U))
#define SNS_12_Get()               ((PIOC_REGS->PIO_PDSR >> 21U) & 0x1U)
#define SNS_12_PIN                  PIO_PIN_PC21

/*** Macros for SNS_3 pin ***/
#define SNS_3_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<22U))
#define SNS_3_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<22U))
#define SNS_3_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<22U))
#define SNS_3_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<22U))
#define SNS_3_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<22U))
#define SNS_3_Get()               ((PIOC_REGS->PIO_PDSR >> 22U) & 0x1U)
#define SNS_3_PIN                  PIO_PIN_PC22

/*** Macros for LED1 pin ***/
#define LED1_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<5U))
#define LED1_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<5U))
#define LED1_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<5U))
#define LED1_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<5U))
#define LED1_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<5U))
#define LED1_Get()               ((PIOD_REGS->PIO_PDSR >> 5U) & 0x1U)
#define LED1_PIN                  PIO_PIN_PD5

/*** Macros for LP_FR pin ***/
#define LP_FR_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<4U))
#define LP_FR_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<4U))
#define LP_FR_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<4U))
#define LP_FR_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<4U))
#define LP_FR_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<4U))
#define LP_FR_Get()               ((PIOD_REGS->PIO_PDSR >> 4U) & 0x1U)
#define LP_FR_PIN                  PIO_PIN_PD4

/*** Macros for SNS_13 pin ***/
#define SNS_13_Set()               (PIOC_REGS->PIO_SODR = ((uint32_t)1U<<23U))
#define SNS_13_Clear()             (PIOC_REGS->PIO_CODR = ((uint32_t)1U<<23U))
#define SNS_13_Toggle()            (PIOC_REGS->PIO_ODSR ^= ((uint32_t)1U<<23U))
#define SNS_13_OutputEnable()      (PIOC_REGS->PIO_OER = ((uint32_t)1U<<23U))
#define SNS_13_InputEnable()       (PIOC_REGS->PIO_ODR = ((uint32_t)1U<<23U))
#define SNS_13_Get()               ((PIOC_REGS->PIO_PDSR >> 23U) & 0x1U)
#define SNS_13_PIN                  PIO_PIN_PC23

/*** Macros for PUMP2 pin ***/
#define PUMP2_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<3U))
#define PUMP2_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<3U))
#define PUMP2_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<3U))
#define PUMP2_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<3U))
#define PUMP2_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<3U))
#define PUMP2_Get()               ((PIOD_REGS->PIO_PDSR >> 3U) & 0x1U)
#define PUMP2_PIN                  PIO_PIN_PD3

/*** Macros for LED4 pin ***/
#define LED4_Set()               (PIOA_REGS->PIO_SODR = ((uint32_t)1U<<29U))
#define LED4_Clear()             (PIOA_REGS->PIO_CODR = ((uint32_t)1U<<29U))
#define LED4_Toggle()            (PIOA_REGS->PIO_ODSR ^= ((uint32_t)1U<<29U))
#define LED4_OutputEnable()      (PIOA_REGS->PIO_OER = ((uint32_t)1U<<29U))
#define LED4_InputEnable()       (PIOA_REGS->PIO_ODR = ((uint32_t)1U<<29U))
#define LED4_Get()               ((PIOA_REGS->PIO_PDSR >> 29U) & 0x1U)
#define LED4_PIN                  PIO_PIN_PA29

/*** Macros for PUMP1 pin ***/
#define PUMP1_Set()               (PIOD_REGS->PIO_SODR = ((uint32_t)1U<<2U))
#define PUMP1_Clear()             (PIOD_REGS->PIO_CODR = ((uint32_t)1U<<2U))
#define PUMP1_Toggle()            (PIOD_REGS->PIO_ODSR ^= ((uint32_t)1U<<2U))
#define PUMP1_OutputEnable()      (PIOD_REGS->PIO_OER = ((uint32_t)1U<<2U))
#define PUMP1_InputEnable()       (PIOD_REGS->PIO_ODR = ((uint32_t)1U<<2U))
#define PUMP1_Get()               ((PIOD_REGS->PIO_PDSR >> 2U) & 0x1U)
#define PUMP1_PIN                  PIO_PIN_PD2


// *****************************************************************************
/* PIO Port

  Summary:
    Identifies the available PIO Ports.

  Description:
    This enumeration identifies the available PIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


#define    PIO_PORT_A       (PIOA_BASE_ADDRESS)
#define    PIO_PORT_B       (PIOB_BASE_ADDRESS)
#define     PIO_PORT_C      (PIOC_BASE_ADDRESS)
#define     PIO_PORT_D      (PIOD_BASE_ADDRESS)
#define     PIO_PORT_E      (PIOE_BASE_ADDRESS)
typedef uint32_t PIO_PORT;

// *****************************************************************************
/* PIO Port Pins

  Summary:
    Identifies the available PIO port pins.

  Description:
    This enumeration identifies the available PIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

#define    PIO_PIN_PA0     (0U)
#define    PIO_PIN_PA1     (1U)
#define    PIO_PIN_PA2     (2U)
#define    PIO_PIN_PA3     (3U)
#define    PIO_PIN_PA4     (4U)
#define    PIO_PIN_PA5     (5U)
#define    PIO_PIN_PA6     (6U)
#define    PIO_PIN_PA7     (7U)
#define    PIO_PIN_PA8     (8U)
#define    PIO_PIN_PA9     (9U)
#define    PIO_PIN_PA10     (10U)
#define    PIO_PIN_PA11     (11U)
#define    PIO_PIN_PA12     (12U)
#define    PIO_PIN_PA13     (13U)
#define    PIO_PIN_PA14     (14U)
#define    PIO_PIN_PA15     (15U)
#define    PIO_PIN_PA16     (16U)
#define    PIO_PIN_PA17     (17U)
#define    PIO_PIN_PA18     (18U)
#define    PIO_PIN_PA19     (19U)
#define    PIO_PIN_PA20     (20U)
#define    PIO_PIN_PA21     (21U)
#define    PIO_PIN_PA22     (22U)
#define    PIO_PIN_PA23     (23U)
#define    PIO_PIN_PA24     (24U)
#define    PIO_PIN_PA25     (25U)
#define    PIO_PIN_PA26     (26U)
#define    PIO_PIN_PA27     (27U)
#define    PIO_PIN_PA28     (28U)
#define    PIO_PIN_PA29     (29U)
#define    PIO_PIN_PA30     (30U)
#define    PIO_PIN_PA31     (31U)
#define    PIO_PIN_PB0     (32U)
#define    PIO_PIN_PB1     (33U)
#define    PIO_PIN_PB2     (34U)
#define    PIO_PIN_PB3     (35U)
#define    PIO_PIN_PB4     (36U)
#define    PIO_PIN_PB5     (37U)
#define    PIO_PIN_PB6     (38U)
#define    PIO_PIN_PB7     (39U)
#define    PIO_PIN_PB8     (40U)
#define    PIO_PIN_PB9     (41U)
#define    PIO_PIN_PB12     (44U)
#define    PIO_PIN_PB13     (45U)
#define    PIO_PIN_PC0     (64U)
#define    PIO_PIN_PC1     (65U)
#define    PIO_PIN_PC2     (66U)
#define    PIO_PIN_PC3     (67U)
#define    PIO_PIN_PC4     (68U)
#define    PIO_PIN_PC5     (69U)
#define    PIO_PIN_PC6     (70U)
#define    PIO_PIN_PC7     (71U)
#define    PIO_PIN_PC8     (72U)
#define    PIO_PIN_PC9     (73U)
#define    PIO_PIN_PC10     (74U)
#define    PIO_PIN_PC11     (75U)
#define    PIO_PIN_PC12     (76U)
#define    PIO_PIN_PC13     (77U)
#define    PIO_PIN_PC14     (78U)
#define    PIO_PIN_PC15     (79U)
#define    PIO_PIN_PC16     (80U)
#define    PIO_PIN_PC17     (81U)
#define    PIO_PIN_PC18     (82U)
#define    PIO_PIN_PC19     (83U)
#define    PIO_PIN_PC20     (84U)
#define    PIO_PIN_PC21     (85U)
#define    PIO_PIN_PC22     (86U)
#define    PIO_PIN_PC23     (87U)
#define    PIO_PIN_PC24     (88U)
#define    PIO_PIN_PC25     (89U)
#define    PIO_PIN_PC26     (90U)
#define    PIO_PIN_PC27     (91U)
#define    PIO_PIN_PC28     (92U)
#define    PIO_PIN_PC29     (93U)
#define    PIO_PIN_PC30     (94U)
#define    PIO_PIN_PC31     (95U)
#define    PIO_PIN_PD0     (96U)
#define    PIO_PIN_PD1     (97U)
#define    PIO_PIN_PD2     (98U)
#define    PIO_PIN_PD3     (99U)
#define    PIO_PIN_PD4     (100U)
#define    PIO_PIN_PD5     (101U)
#define    PIO_PIN_PD6     (102U)
#define    PIO_PIN_PD7     (103U)
#define    PIO_PIN_PD8     (104U)
#define    PIO_PIN_PD9     (105U)
#define    PIO_PIN_PD10     (106U)
#define    PIO_PIN_PD11     (107U)
#define    PIO_PIN_PD12     (108U)
#define    PIO_PIN_PD13     (109U)
#define    PIO_PIN_PD14     (110U)
#define    PIO_PIN_PD15     (111U)
#define    PIO_PIN_PD16     (112U)
#define    PIO_PIN_PD17     (113U)
#define    PIO_PIN_PD18     (114U)
#define    PIO_PIN_PD19     (115U)
#define    PIO_PIN_PD20     (116U)
#define    PIO_PIN_PD21     (117U)
#define    PIO_PIN_PD22     (118U)
#define    PIO_PIN_PD23     (119U)
#define    PIO_PIN_PD24     (120U)
#define    PIO_PIN_PD25     (121U)
#define    PIO_PIN_PD26     (122U)
#define    PIO_PIN_PD27     (123U)
#define    PIO_PIN_PD28     (124U)
#define    PIO_PIN_PD29     (125U)
#define    PIO_PIN_PD30     (126U)
#define    PIO_PIN_PD31     (127U)
#define    PIO_PIN_PE0     (128U)
#define    PIO_PIN_PE1     (129U)
#define    PIO_PIN_PE2     (130U)
#define    PIO_PIN_PE3     (131U)
#define    PIO_PIN_PE4     (132U)
#define    PIO_PIN_PE5     (133U)

    /* This element should not be used in any of the PIO APIs.
       It will be used by other modules or application to denote that none of the PIO Pin is used */
#define    PIO_PIN_NONE         ( -1)

typedef uint32_t PIO_PIN;


void PIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t PIO_PortRead(PIO_PORT port);

void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

uint32_t PIO_PortLatchRead ( PIO_PORT port );

void PIO_PortSet(PIO_PORT port, uint32_t mask);

void PIO_PortClear(PIO_PORT port, uint32_t mask);

void PIO_PortToggle(PIO_PORT port, uint32_t mask);

void PIO_PortInputEnable(PIO_PORT port, uint32_t mask);

void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void PIO_PinWrite(PIO_PIN pin, bool value)
{
    PIO_PortWrite((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), (uint32_t)(0x1) << (pin & 0x1fU), (uint32_t)(value) << (pin & 0x1fU));
}

static inline bool PIO_PinRead(PIO_PIN pin)
{
    return (bool)((PIO_PortRead((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U)))) >> (pin & 0x1FU)) & 0x1U);
}

static inline bool PIO_PinLatchRead(PIO_PIN pin)
{
    return (bool)((PIO_PortLatchRead((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U)))) >> (pin & 0x1FU)) & 0x1U);
}

static inline void PIO_PinToggle(PIO_PIN pin)
{
    PIO_PortToggle((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinSet(PIO_PIN pin)
{
    PIO_PortSet((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinClear(PIO_PIN pin)
{
    PIO_PortClear((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinInputEnable(PIO_PIN pin)
{
    PIO_PortInputEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinOutputEnable(PIO_PIN pin)
{
    PIO_PortOutputEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_PIO_H
