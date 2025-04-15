#ifndef __USART2_H__
#define __USART2_H__

#include <stdint.h>

void Usart2_SendData(const void* data, uint16_t size);
void Usart2_SendArray(uint8_t *array, uint16_t length);
void Usart2_SendString(char *String);
void Usart2_Init(void);

#endif
