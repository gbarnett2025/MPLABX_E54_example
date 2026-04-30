


#ifndef UARTTASK_H
#define UARTTASK_H

void makeUartTask(void);

extern uint8_t rxByteGlobal;
void SERCOM0_USART_ReadCallback(uintptr_t context);
extern QueueHandle_t uartRxQueue;
#endif /* UARTTASK_H */