#include "usart.h"
#include "Usart3.h"
#include <stdarg.h>
#include <string.h>


volatile float global_angle;						//����Ƕȱ���(ȫ��)
uint8_t temprx3;												//�洢��������



void Usart3_SendByte(uint8_t Byte)
{
    HAL_UART_Transmit(&huart3, &Byte, 1, 1000);
}

void Usart3_SendArray(uint8_t *array, uint16_t length)
{
    HAL_UART_Transmit(&huart3, array, length, 1000);
    Usart3_SendByte(0x0D);//���ͻس���
    Usart3_SendByte(0x0A);//���ͻ��з�
    HAL_Delay(200);
}

void Usart3_SendString(char *String)
{
    HAL_UART_Transmit(&huart3, (uint8_t*)String, strlen(String), 1000);
}

void Usart3_Init(){
	// ���������ж�
	HAL_UART_Receive_IT(&huart3,&temprx3,1);
}

float Usart_GetAngle(){
	return global_angle;
}



