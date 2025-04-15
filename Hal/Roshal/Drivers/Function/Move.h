#ifndef __MOVE_H__
#define __MOVE_H__

#include <stdint.h>

void Motor_Init();

//设置左右轮速度
void Left_Speed(int8_t speed);
void Right_Speed(int8_t speed);

//读取左右轮速度
int8_t Motor2_GetSpeed(void);
int8_t Motor3_GetSpeed(void);

//读取左右轮转动脉冲
uint32_t Motor2_GetStep(void);
uint32_t Motor3_GetStep(void);

#endif
