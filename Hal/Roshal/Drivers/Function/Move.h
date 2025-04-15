#ifndef __MOVE_H__
#define __MOVE_H__

#include <stdint.h>

void Motor_Init();

//�����������ٶ�
void Left_Speed(int8_t speed);
void Right_Speed(int8_t speed);

//��ȡ�������ٶ�
int8_t Motor2_GetSpeed(void);
int8_t Motor3_GetSpeed(void);

//��ȡ������ת������
uint32_t Motor2_GetStep(void);
uint32_t Motor3_GetStep(void);

#endif
