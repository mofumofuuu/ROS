#include "H_Tmc2209.h"
#include "gpio.h"
#include "tim.h"

//2�ŵ��Ԥ���뵱ǰֵ
extern uint8_t current2_level;
extern uint32_t step2;
//3�ŵ��Ԥ���뵱ǰֵ
extern uint8_t current3_level;
extern uint32_t step3;

int8_t turn=0;

//motor2 left motor3 right

void Motor_Init(){
	HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim8);
	HAL_TIM_Base_Start_IT(&htim5);
}

//�������ҵ���ٶ�
void Left_Speed(int8_t speed){
	if(speed==0){
		//ʧ�ܲ������
		Motor2_Enable(DISABLE);
	}else if(speed>0){
		//ʹ�ܲ������
		Motor2_Enable(ENABLE);
		//����ѡ��Ϊ��
		Motor2_Direction(GPIO_PIN_SET);
		turn=1;
		//�����ٶ�
		Motor2_SetSpeed(speed-1);
	}else{
		//ʹ�ܲ������
		Motor2_Enable(ENABLE);
		//����ѡ��Ϊ��
		Motor2_Direction(GPIO_PIN_RESET);
		turn=-1;
		//�����ٶ�
		Motor2_SetSpeed(-speed-1);
	}
}

void Right_Speed(int8_t speed){
	if(speed==0){
		//ʧ�ܲ������
		Motor3_Enable(DISABLE);
	}else if(speed>0){
		//ʹ�ܲ������
		Motor3_Enable(ENABLE);
		//����ѡ��Ϊ��
		Motor3_Direction(GPIO_PIN_SET);
		turn=1;
		//�����ٶ�
		Motor3_SetSpeed(speed-1);
	}else{
		//ʹ�ܲ������
		Motor3_Enable(ENABLE);
		//����ѡ��Ϊ��
		Motor3_Direction(GPIO_PIN_RESET);
		turn=-1;
		//�����ٶ�
		Motor3_SetSpeed(-speed-1);
	}
}

//��ȡ���ҵ���ٶ�
int8_t Motor2_GetSpeed(){
	return turn*(current2_level+1);
}

int8_t Motor3_GetSpeed(){
	return turn*(current3_level+1);
}

//ת260wȦ�ᳬ����Χ
//��ȡ���ҵ������
uint32_t Motor2_GetStep(){
	return step2;
}
uint32_t Motor3_GetStep(){
	return step3;
}
