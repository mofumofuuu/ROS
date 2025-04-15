#include "H_Tmc2209.h"
#include "gpio.h"
#include "tim.h"

//2号电机预计与当前值
extern uint8_t current2_level;
extern uint32_t step2;
//3号电机预计与当前值
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

//设置左右电机速度
void Left_Speed(int8_t speed){
	if(speed==0){
		//失能步进电机
		Motor2_Enable(DISABLE);
	}else if(speed>0){
		//使能步进电机
		Motor2_Enable(ENABLE);
		//方向选择为正
		Motor2_Direction(GPIO_PIN_SET);
		turn=1;
		//设置速度
		Motor2_SetSpeed(speed-1);
	}else{
		//使能步进电机
		Motor2_Enable(ENABLE);
		//方向选择为反
		Motor2_Direction(GPIO_PIN_RESET);
		turn=-1;
		//设置速度
		Motor2_SetSpeed(-speed-1);
	}
}

void Right_Speed(int8_t speed){
	if(speed==0){
		//失能步进电机
		Motor3_Enable(DISABLE);
	}else if(speed>0){
		//使能步进电机
		Motor3_Enable(ENABLE);
		//方向选择为正
		Motor3_Direction(GPIO_PIN_SET);
		turn=1;
		//设置速度
		Motor3_SetSpeed(speed-1);
	}else{
		//使能步进电机
		Motor3_Enable(ENABLE);
		//方向选择为反
		Motor3_Direction(GPIO_PIN_RESET);
		turn=-1;
		//设置速度
		Motor3_SetSpeed(-speed-1);
	}
}

//读取左右电机速度
int8_t Motor2_GetSpeed(){
	return turn*(current2_level+1);
}

int8_t Motor3_GetSpeed(){
	return turn*(current3_level+1);
}

//转260w圈会超出范围
//读取左右电机脉冲
uint32_t Motor2_GetStep(){
	return step2;
}
uint32_t Motor3_GetStep(){
	return step3;
}
