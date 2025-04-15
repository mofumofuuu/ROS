#include "tim.h"
#include "gpio.h"
#include "math.h"
#include "H_Tmc2209.h"

//2�ŵ��Ԥ���뵱ǰֵ
uint8_t current2_level=0,target2_level=0;
uint32_t step2=0;
//3�ŵ��Ԥ���뵱ǰֵ
uint8_t current3_level=0,target3_level=0;
uint32_t step3=0;

//��λ0��40hz 24999 ��λ39��1600hz 624
int speed_levels[40]={24999,12499,8332,6249,4999,4165,3570,3124,2776,2499,2271,2082,1922,1784,1665,1561,1469,
	1387,1314,1249,1189,1135,1085,1040,999,960,924,891,861,832,805,780,756,734,713,693,674,656,640,624};

void Motor2_SetSpeed(uint8_t level){
	if(level>MAX_SPEED_LEVEL) level=MAX_SPEED_LEVEL;	//�޷�
	target2_level = level;															//����Ŀ��ȼ�
}
void Motor3_SetSpeed(uint8_t level){
	if(level>MAX_SPEED_LEVEL) level=MAX_SPEED_LEVEL;	//�޷�
	target3_level = level;															//����Ŀ��ȼ�
}

//DISABLE OR ENABLE
//ѡ���Ƿ�ʹ��
void Motor2_Enable(FunctionalState state) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (state == ENABLE) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
//ѡ���Ƿ�ʹ��
void Motor3_Enable(FunctionalState state) {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, (state == ENABLE) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

//GPIO_PIN_RESET OR GPIO_PIN_SET
//ѡ����vccΪ��
void Motor2_Direction(GPIO_PinState dir) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, dir);
}
//ѡ����vccΪ��
void Motor3_Direction(GPIO_PinState dir) {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, dir);
}


//����tim5��ʱ�ж����ڵ���arr��ccr
//����tim8�����ж����ڼ���������
//����tim2ȫ���ж����ڼ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim5) {
        // �𲽱ƽ�Ŀ�굵λ
        if (current2_level < target2_level) current2_level++;
        else if (current2_level > target2_level) current2_level--;
			
			// �𲽱ƽ�Ŀ�굵λ
        if (current3_level < target3_level) current3_level++;
        else if (current3_level > target3_level) current3_level--;
        
        // ����TIM2����
        uint32_t new_arr2 = speed_levels[current2_level];
				uint32_t new_arr3 = speed_levels[current3_level];
			
        __HAL_TIM_SET_AUTORELOAD(&htim2, new_arr2);      // ����ARR
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, new_arr2 / 2); // 50%ռ�ձ�
			
				__HAL_TIM_SET_AUTORELOAD(&htim8, new_arr3);      // ����ARR
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, new_arr3 / 2); // 50%ռ�ձ�
    }else if (htim == &htim2) {
      // TIM2ÿ���������ڼ���
			step2++;
    }
    else if (htim == &htim8) {
      // TIM8ÿ���������ڼ���
			step3++;
    }
}
