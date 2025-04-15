#include "usart.h"
#include "Usart3.h"
#include <stdarg.h>
#include <string.h>


volatile float global_angle;						//定义角度变量(全局)
uint8_t temprx3;												//存储接收数据



void Usart3_SendByte(uint8_t Byte)
{
    HAL_UART_Transmit(&huart3, &Byte, 1, 1000);
}

void Usart3_SendArray(uint8_t *array, uint16_t length)
{
    HAL_UART_Transmit(&huart3, array, length, 1000);
    Usart3_SendByte(0x0D);//发送回车符
    Usart3_SendByte(0x0A);//发送换行符
    HAL_Delay(200);
}

void Usart3_SendString(char *String)
{
    HAL_UART_Transmit(&huart3, (uint8_t*)String, strlen(String), 1000);
}

void Usart3_Init(){
	// 启动接收中断
	HAL_UART_Receive_IT(&huart3,&temprx3,1);
}

float Usart_GetAngle(){
	return global_angle;
}



