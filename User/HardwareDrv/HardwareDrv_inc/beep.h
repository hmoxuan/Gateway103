/**
 * beep.h file for STM32F103.
 * Describtion: beep control module
 * Author: qinfei 2015.03.30
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#ifndef __BEEP_H__
#define __BEEP_H__

#include "sys.h"

//�������˿ڶ���
#define BEEP PBout(8)// BEEP,�������ӿ�		   

void BEEP_Init(void);//��ʼ��

void BEEP_Module_Test(void);
		 				    
#endif  /*__BEEP_H__*/