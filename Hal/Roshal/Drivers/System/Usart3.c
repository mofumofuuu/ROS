#include "usart.h"
#include "Usart3.h"
#include <stdarg.h>
#include <string.h>


extern volatile float global_angle;						//定义角度变量(全局)
extern volatile uint8_t new_data_received;		//定义数据接收
uint8_t temprx;												//存储接收数据

uint8_t unlock_register[] = {0xFF, 0xAA, 0x69, 0x88, 0xB5};
uint8_t reset_z_axis[] = {0xFF, 0xAA, 0x76, 0x00, 0x00};
uint8_t set_output_200Hz[] = {0xFF, 0xAA, 0x03, 0x0B, 0x00};
uint8_t set_baudrate_115200[] = {0xFF, 0xAA, 0x04, 0x06, 0x00};
uint8_t save_settings[] = {0xFF, 0xAA, 0x00, 0x00, 0x00};
uint8_t restart_device[] = {0xFF, 0xAA, 0x00, 0xFF, 0x00};

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
	//发送配置命令
	Usart3_SendArray(unlock_register, sizeof(unlock_register));
  Usart3_SendArray(reset_z_axis, sizeof(reset_z_axis));
  Usart3_SendArray(set_output_200Hz, sizeof(set_output_200Hz));
  Usart3_SendArray(set_baudrate_115200, sizeof(set_baudrate_115200));
  Usart3_SendArray(save_settings, sizeof(save_settings));
  Usart3_SendArray(restart_device, sizeof(restart_device));
	
	// 启动接收中断
	HAL_UART_Receive_IT(&huart3,&temprx,1);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	
	static uint8_t rx_buffer[11];			//接收缓冲区
	static uint8_t rx_index = 0;			//第几位
  static uint8_t state = 0; 				// 0: 寻找包头，1: 接收数据
	
	if(huart==&huart3){//是串口三触发的中断
		if(state==0){//寻找包头状态
			
			if(temprx==0x55){//找到包头
				rx_buffer[0]=temprx;
				rx_index=1;
				state=1;
			}
			
		}else if(state ==1 ){//接收数据状态
			
			if(rx_index!=10){//没接收完
				
				if(temprx!=0x53&&rx_index==1){//第二个数据部位0x53
					//重新查询包头
					rx_index=0;
					state=0;
				}else{
					rx_buffer[rx_index]=temprx;
					rx_index++;
				}
				
			}else{//接收完
				rx_buffer[rx_index]=temprx;
				//存入数据
				global_angle = ((int16_t)((rx_buffer[7] << 8) | rx_buffer[6])) / 32768.0f * 180.0f;
				//重新查询包头
				rx_index=0;
				state=0;
				
			}
			
			
		}
		
		
		HAL_UART_Receive_IT(&huart3,&temprx,1);
	}
	
}

