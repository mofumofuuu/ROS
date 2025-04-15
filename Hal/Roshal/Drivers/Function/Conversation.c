#include "usart.h"
#include "Usart2.h"					//���ͽ�������
#include "H_Hwt101.h"				//���ͽǶ�
#include "Move.h"						//�����ٶ��Լ�����

extern volatile float global_angle;						//����Ƕȱ���(ȫ��)
extern uint8_t temprx3;												//�洢��������

extern uint8_t temprx2; 														//�洢��������

uint8_t headline=0xff,deadline=0xfe;

int8_t RL_speed,RR_speed;		//��ʵ�ٶȷ�Χ-40-40
uint32_t RL_step,RR_step;		//��ʵ����
float Rangle;								//��ǰ�Ƕ�

//��������
void Hx_Send(){
	Usart2_SendData(&headline,1);//���Ͱ�ͷ
	
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

	Usart2_SendData(&deadline,1);//���Ͱ�β
}

void HX_Receive(){
	//���������ж�
	HAL_UART_Receive_IT(&huart2,&temprx2,1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	
	static uint8_t state2 = 0; 				// 0: Ѱ�Ұ�ͷ��1: ��������, 2:���հ�β
	static uint8_t rx2_index = 0;			//�ڼ�λ
	
	static uint8_t rx3_buffer[11];			//���ջ�����
	static uint8_t rx3_index = 0;			//�ڼ�λ
  static uint8_t state3 = 0; 				// 0: Ѱ�Ұ�ͷ��1: ��������
	
	if(huart==&huart2){//�Ǵ��ڶ��������ж�
		if(state2==0){//Ѱ�Ұ�ͷ
			if(temprx2==0xff){
				//�������ݡ�
				state2=1;
			}
		}else if(state2==1){//��������
			
			
		}else{
			
		}
			
		HAL_UART_Receive_IT(&huart2,&temprx2,1);
	}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(huart==&huart3){//�Ǵ������������ж�
		if(state3==0){//Ѱ�Ұ�ͷ״̬
			
			if(temprx3==0x55){//�ҵ���ͷ
				rx3_buffer[0]=temprx3;
				rx3_index=1;
				state3=1;
			}
			
		}else if(state3 ==1 ){//��������״̬
			
			if(rx3_index!=10){//û������
				
				if(temprx3!=0x53&&rx3_index==1){//�ڶ������ݲ�λ0x53
					//���²�ѯ��ͷ
					rx3_index=0;
					state3=0;
				}else{
					rx3_buffer[rx3_index]=temprx3;
					rx3_index++;
				}
				
			}else{//������
				rx3_buffer[rx3_index]=temprx3;
				//��������
				global_angle = ((int16_t)((rx3_buffer[7] << 8) | rx3_buffer[6])) / 32768.0f * 180.0f;
				//���²�ѯ��ͷ
				rx3_index=0;
				state3=0;
				
			}
			
			
		}
		
		
		HAL_UART_Receive_IT(&huart3,&temprx3,1);
	}
	
}
