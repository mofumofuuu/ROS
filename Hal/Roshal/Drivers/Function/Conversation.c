#include "usart.h"
#include "Usart2.h"					//发送接收数据
#include "H_Hwt101.h"				//发送角度
#include "Move.h"						//发送速度以及步数

extern volatile float global_angle;						//定义角度变量(全局)
extern uint8_t temprx3;												//存储接收数据

extern uint8_t temprx2; 														//存储接受数据

uint8_t headline=0xff,deadline=0xfe;

int8_t RL_speed,RR_speed;		//真实速度范围-40-40
uint32_t RL_step,RR_step;		//真实步数
float Rangle;								//当前角度

//发送数据
void Hx_Send(){
	Usart2_SendData(&headline,1);//发送包头
	
	RL_speed = Motor2_GetSpeed();
	RR_speed = Motor2_GetSpeed();
	
	RL_step = Motor2_GetStep();
	RR_step =	Motor3_GetStep();
	
	Rangle = Hwt101_GetAngle();
	
	Usart2_SendData(&RL_speed,sizeof(RL_speed));
	Usart2_SendData(&RR_speed,sizeof(RR_speed));
	
	Usart2_SendData(&RL_step,sizeof(RL_step));
	Usart2_SendData(&RR_step,sizeof(RR_step));
	
	Usart2_SendData(&Rangle,sizeof(Rangle));

	Usart2_SendData(&deadline,1);//发送包尾
}

void HX_Receive(){
	//开启接收中断
	HAL_UART_Receive_IT(&huart2,&temprx2,1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	
	static uint8_t state2 = 0; 				// 0: 寻找包头，1: 接收数据, 2:接收包尾
	static uint8_t rx2_index = 0;			//第几位
	
	static uint8_t rx3_buffer[11];			//接收缓冲区
	static uint8_t rx3_index = 0;			//第几位
  static uint8_t state3 = 0; 				// 0: 寻找包头，1: 接收数据
	
	if(huart==&huart2){//是串口二触发的中断
		if(state2==0){//寻找包头
			if(temprx2==0xff){
				//接收数据“
				state2=1;
			}
		}else if(state2==1){//接收数据
			
			
		}else{
			
		}
			
		HAL_UART_Receive_IT(&huart2,&temprx2,1);
	}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(huart==&huart3){//是串口三触发的中断
		if(state3==0){//寻找包头状态
			
			if(temprx3==0x55){//找到包头
				rx3_buffer[0]=temprx3;
				rx3_index=1;
				state3=1;
			}
			
		}else if(state3 ==1 ){//接收数据状态
			
			if(rx3_index!=10){//没接收完
				
				if(temprx3!=0x53&&rx3_index==1){//第二个数据部位0x53
					//重新查询包头
					rx3_index=0;
					state3=0;
				}else{
					rx3_buffer[rx3_index]=temprx3;
					rx3_index++;
				}
				
			}else{//接收完
				rx3_buffer[rx3_index]=temprx3;
				//存入数据
				global_angle = ((int16_t)((rx3_buffer[7] << 8) | rx3_buffer[6])) / 32768.0f * 180.0f;
				//重新查询包头
				rx3_index=0;
				state3=0;
				
			}
			
			
		}
		
		
		HAL_UART_Receive_IT(&huart3,&temprx3,1);
	}
	
}
