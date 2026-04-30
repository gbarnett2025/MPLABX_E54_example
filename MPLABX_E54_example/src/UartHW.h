


#ifndef UARTHW_H
#define UARTHW_H
void setUart0ReadCallbackBridge(void);
bool uart0ReadBridge( void *buffer, const size_t size );
bool uart0WriteBridge( void *buffer, const size_t size );
#endif /* UARTHW_H */