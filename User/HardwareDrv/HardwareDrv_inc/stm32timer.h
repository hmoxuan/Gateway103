/**
 * stm32timer.h file for STM32F103.
 * Describtion:  STM32 ��ʱ��
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#ifndef __STM32TIMER_H__
#define __STM32TIMER_H__

#include "sys.h"
#include "myportmacro.h"//�������ͺ궨��

/*ϵͳʱ��*/
void TIM6_Int_Init(u16 arr,u16 psc);

/*ϵͳʱ�����*/
void Timing_Increase(void);

/*��ȡϵͳ��ǰʱ��*/
uint32 GetSystemNowtime(void);

#endif/*__STM32TIMER_H__*/
