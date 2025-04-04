#ifndef __USART3_H__
#define __USART3_H__

#include <stdio.h>

//配置命令数组
//解锁寄存器 FF AA 69 88 B5
//Z轴角度归零FF AA 76 00 00
//设置200HZ输出 FF AA 03 0B 00
//设置波特率115200 FF AA 04 06 00
//保存 FF AA 00 00 00
//重启 FF AA 00 FF 00
//在上位机配置更简便

void Usart3_Init(void);


#endif
