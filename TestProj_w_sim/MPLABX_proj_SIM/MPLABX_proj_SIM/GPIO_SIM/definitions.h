#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdint.h>    // for C code

// Define pin mappings for the simulated GPIO

#define LED_STATE_PIN    16  // Simulated pin for state indication (e.g., PA16)
#define LED_PWR_PIN      23  // Simulated pin for power indication (e.g., PA23)

typedef uint32_t PIO_PIN;

void PIO_PinClear(PIO_PIN pin);
void PIO_PinSet(PIO_PIN pin);
void SYS_Initialize(void* data);


#endif // DEFINITIONS_H