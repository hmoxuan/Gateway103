/**
 * delay.c file for STM32F103.
 * Describtion: Used to produce ms us delay
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#include "delay.h"

/*******************************************************************************
 *V1.2�޸�˵��
 *�������ж��е��ó�����ѭ���Ĵ���
 *��ֹ��ʱ��׼ȷ,����do while�ṹ!
********************************************************************************/	 
static u8  fac_us=0;    /* us��ʱ������ */
static u16 fac_ms=0;    /* ms��ʱ������ */


/*******************************************************************************
 * ��ʼ���ӳٺ���
 * SYSTICK��ʱ�ӹ̶�ΪHCLKʱ�ӵ�1/8
 * SYSCLK:ϵͳʱ��
********************************************************************************/
void delay_init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);/*ѡ���ⲿʱ��HCLK/8*/
	fac_us=SystemCoreClock/8000000;//Ϊϵͳʱ�ӵ�1/8  		    
	fac_ms=(u16)fac_us*1000;//��ucos��,����ÿ��ms��Ҫ��systickʱ����
}


/*******************************************************************************
 * ��ʱnms
 * ע��nms�ķ�Χ
 * SysTick->LOADΪ24λ�Ĵ���,����,�����ʱΪ:
 * nms<=0xffffff*8*1000/SYSCLK
 * SYSCLK��λΪHz,nms��λΪms
 * ��72M������,nms<=1864 
 * 
********************************************************************************/
void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;/*ʱ�����(SysTick->LOADΪ24bit)*/	
	SysTick->VAL =0x00;           /*��ռ�����*/	
	SysTick->CTRL=0x01 ;          /*��ʼ����*/	
        
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));/*�ȴ�ʱ�䵽��*/
        
	SysTick->CTRL=0x00;     /*�رռ�����*/	
	SysTick->VAL =0X00;     /*��ռ�����*/		  	    
}   

/*******************************************************************************
 * ��ʱnus
 * nusΪҪ��ʱ��us��.
********************************************************************************/	    								   
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; /*ʱ�����*/	  		 
	SysTick->VAL=0x00;        /*��ռ�����*/
	SysTick->CTRL=0x01;       /*��ʼ����*/ 	
        
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));/*�ȴ�ʱ�䵽��*/
        
	SysTick->CTRL=0x00;     /*�رռ�����*/
	SysTick->VAL =0X00;     /*��ռ�����*/	 
}