/**
 * keys.h file for STM32F103.
 * Describtion:  key control module
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#ifndef __KEYS_H__
#define __KEYS_H__

#include "stm32f10x.h"
#include "sys.h"

/* KEY�˿ڶ��� */
#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����1
#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//��ȡ����2 
#define KEY3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����3(WK_UP) 

#define KEY_UP 		4
#define KEY_LEFT	3
#define KEY_DOWN	2
#define KEY_RIGHT	1
	 
void KEY_Init(void);       /* ����IO�ڳ�ʼ�� */
void KEY_Module_Test(void);/* LEDSģ����� */
		 				    
#endif  /*__KEYS_H__*/