
#include "definitions.h"
#include <stdio.h>

void PIO_PinSet(PIO_PIN pin)
{
	printf("PIO_PinSet: Setting pin %d HIGH\n", pin);	
}


void PIO_PinClear(PIO_PIN pin)
{
	printf("PIO_PinClear: Setting pin %d LOW\n", pin);
}

void SYS_Initialize(void* data)
{
	printf("SYS_Initialize: System initialization complete.\n");
}