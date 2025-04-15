#include "usart.h"
#include "string.h"

uint8_t temprx2; 														//�洢��������

// ͨ�����ݷ���ģ��
void Usart2_SendData(const void* data, uint16_t size)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)data, size, 1000);
}

void Usart2_SendArray(uint8_t *array, uint16_t length)
{
    HAL_UART_Transmit(&huart2, array, length, 1000);
}

void Usart2_SendString(char *String)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)String, strlen(String), 1000);
}

void Usart2_Init(){
	// ���������ж�
	HAL_UART_Receive_IT(&huart2,&temprx2,1);
}


