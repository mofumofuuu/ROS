#include "Usart3.h"
#include "stdio.h"

#include <stdint.h>

uint8_t unlock_register[] = {0xFF, 0xAA, 0x69, 0x88, 0xB5};
uint8_t reset_z_axis[] = {0xFF, 0xAA, 0x76, 0x00, 0x00};
uint8_t set_output_200Hz[] = {0xFF, 0xAA, 0x03, 0x0B, 0x00};
uint8_t set_baudrate_115200[] = {0xFF, 0xAA, 0x04, 0x06, 0x00};
uint8_t save_settings[] = {0xFF, 0xAA, 0x00, 0x00, 0x00};
uint8_t restart_device[] = {0xFF, 0xAA, 0x00, 0xFF, 0x00};

void Hwt101_Init(){
	//∑¢ÀÕ≈‰÷√√¸¡Ó
	Usart3_SendArray(unlock_register, sizeof(unlock_register));
  Usart3_SendArray(reset_z_axis, sizeof(reset_z_axis));
  Usart3_SendArray(set_output_200Hz, sizeof(set_output_200Hz));
  Usart3_SendArray(set_baudrate_115200, sizeof(set_baudrate_115200));
  Usart3_SendArray(save_settings, sizeof(save_settings));
  Usart3_SendArray(restart_device, sizeof(restart_device));
	
	Usart3_Init();
}

float Hwt101_GetAngle(){
	float angle;
	angle=Usart_GetAngle();
	return angle;
}
