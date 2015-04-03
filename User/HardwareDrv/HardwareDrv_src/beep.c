/**
 * beep.c file for STM32F103.
 * Describtion: beep control module
 * Author: qinfei 2015.03.30
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#include "beep.h"
#include "delay.h"
#include "leds.h" 

//��ʼ��PB8Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
void BEEP_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//ʹ��GPIOB�˿�ʱ��
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//BEEP-->PB.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);//���ݲ�����ʼ��GPIOB.8
 
 GPIO_ResetBits(GPIOB,GPIO_Pin_8);//���0���رշ��������
}

void BEEP_Module_Test(void)
{
    LED0=0;
    BEEP=0;		  
    delay_ms(300);//��ʱ300ms
    LED0=1;	  
    BEEP=1;  
    delay_ms(300);//��ʱ300ms
}