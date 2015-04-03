/**
 * usart.h file for STM32F103.
 * Describtion: usart control module
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#ifndef __USART_H__
#define __USART_H__

#include "stdio.h"

/******************************************************************************
 * V1.3�޸�˵�� 
 * ֧����Ӧ��ͬƵ���µĴ��ڲ���������.
 * �����˶�printf��֧��,�����˴��ڽ��������.
 * ������printf��һ���ַ���ʧ��bug.
 ******************************************************************************/ 
extern u8 USART_RX_BUF[64];/* ���ջ���,���63���ֽ�.ĩ�ֽ�Ϊ���з� */ 
extern u8 USART_RX_STA;    /* ����״̬��� */	

void uart1_init(u32 bound);

/*����1ģ����Գ��� */
void USART1_Module_Test(void);
		 				    
#endif  /*__USART_H__*/