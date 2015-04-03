/**
 * leds.c file for STM32F103.
 * Describtion: led control module
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#include "sys.h"
#include "leds.h" 	
#include "delay.h"

/* ��ʼ��PA8��PD2Ϊ�����.��ʹ���������ڵ�ʱ�� */		    
/* LED IO��ʼ�� */
void LED_Init(void)
{
 
    GPIO_InitTypeDef  GPIO_InitStructure;
          
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);/* ʹ��PB�˿�ʱ�� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;		 /* LED0-->PB.5 �˿����� */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 /* ������� */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_5);			 /* PB.5����� */


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);/* ʹ��PD�˿�ʱ�� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	    	 /* LED1-->PE.5 �˿����� */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 /* ������� */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOE, &GPIO_InitStructure);	
    GPIO_SetBits(GPIOE,GPIO_Pin_5); 			 /* PE.5 ����� */
}

void LED_Module_Test(void)
{
    LED0=0;         /* ����ʹ����λ��������Ҳ����ʹ�� GPIO_ResetBits(GPIOA,GPIO_Pin_8); */
    LED1=1;	    /* Ҳ����ʹ�� GPIO_SetBits(GPIOD,GPIO_Pin_2); */
    delay_ms(1000);	
    
    LED0=1;	    /* Ҳ����ʹ�� GPIO_SetBits(GPIOA,GPIO_Pin_8); */	    
    LED1=0; 	    /* Ҳ����ʹ�� GPIO_ResetBits(GPIOD,GPIO_Pin_2) ; */
    delay_ms(1000);	
}
 
