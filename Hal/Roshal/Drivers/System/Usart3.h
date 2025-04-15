#ifndef __USART3_H__
#define __USART3_H__

#include <stdint.h>

//������������
//�����Ĵ��� FF AA 69 88 B5
//Z��Ƕȹ���FF AA 76 00 00
//����200HZ��� FF AA 03 0B 00
//���ò�����115200 FF AA 04 06 00
//���� FF AA 00 00 00
//���� FF AA 00 FF 00
//����λ�����ø����

//�򿪽����ж�
void Usart3_Init(void);
//��������
void Usart3_SendArray(uint8_t *array, uint16_t length);
//��ȡ�Ƕ�����
float Usart_GetAngle(void);


#endif
