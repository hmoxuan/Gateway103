/**
 * leds.h file for STM32F103.
 * Describtion:  led control module
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#ifndef __LEDS_H__
#define __LEDS_H__

#include "stm32f10x.h"

/* LED�˿ڶ��� */
#define LED0 PBout(5)   /* PB5 */
#define LED1 PEout(5)   /* PE5 */	

void LED_Init(void);    /* ��ʼ�� */
void LED_Module_Test(void);/* LEDSģ����� */
		 				    
#endif  /*__LEDS_H__*/