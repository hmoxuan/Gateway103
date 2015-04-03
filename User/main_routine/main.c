/**
 * main.c file for STM32F103.
 * Describtion: main routine
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#include "stm32f10x.h"
#include "delay.h"      //��ʱ����
#include "sys.h"        //STM32 IO �ں궨�弰�жϷ���
#include "leds.h"       //LED
#include "beep.h"       //������
#include "keys.h"       //����
#include "usart.h"      //����
#include "exti.h"       //�ⲿ�ж�
#include "wdg.h"        //���ڿ��Ź�
#include "stm32timer.h" //ϵͳ��ǰʱ��

#include "AppDebugFunc.h"       //���ڵ��Դ�ӡ
#include "AppSoftWareHandler.h"	//APP������

/* �ײ�Ӳ��������ʼ�� */
static void Hardware_Init(void);

/* �ײ�Ӳ������ģ����� */
//static void Hardware_module_test(void);
	   
/* ������ */
int main(void)
{
    /* �ײ�Ӳ��������ʼ�� */
    Hardware_Init();
    
    /*��ӡ������Ϣ*/
    APP_DebugSerialStrOutput("\r\nWelcome To Gateway App ! \r\n");
    
    /*��ʼ��Ӧ�����*/
    SoftWareInit();
    
    while(1)
    {
      /* �ײ�Ӳ������ģ����� */
      //Hardware_module_test();
      
      /*�¼��ڻ�ִ��*/
      SoftWareEventInLoop();
        
      /*��ʱ�¼�ѭ��ִ��*/
      SoftWareTimeingEventInLoop();
    }
}


/* �ײ�Ӳ��������ʼ�� */
static void Hardware_Init(void)
{
    SystemInit(); 	    /* ϵͳʱ�ӳ�ʼ��Ϊ72M: SYSCLK_FREQ_72MHz */
    delay_init();           /* ��ʱ������ʼ�� */	
    TIM6_Int_Init(1000,719);/* 100Khz����Ƶ�ʣ�������1000Ϊ10ms */
        
    NVIC_Configuration();   /* ����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� */
    LED_Init();		    /* LED�˿ڳ�ʼ�� */
    BEEP_Init();            /* ��ʼ���������˿� */
    KEY_Init();             /* �����˿ڳ�ʼ�� */
    uart1_init(9600);       /* ����1��ʼ����������9600 */
    //EXTIX_Init();           /* �ⲿ�жϳ�ʼ��:����Ҫʱһ��Ҫע�͵� */
    WWDG_Init(0X7F,0X5F,WWDG_Prescaler_8);/*������ֵΪ7f,���ڼĴ���Ϊ5f,��Ƶ��Ϊ8*/  
    
    
    /*�ײ�Ӳ��������ʼ�����*/
    APP_DebugSerialStrOutput("\r\n Hardware Init sucessfully ! \r\n");
}

///* �ײ�Ӳ������ģ����� */
//static void Hardware_module_test(void)
//{
//    /* 1.LEDSģ����� */ 
//    //LED_Module_Test();
//  
//    /* 2.BEEPģ����� */ 
//    //BEEP_Module_Test();
//    
//    /* 3.����ģ����� */
//    //KEY_Module_Test();
//
//    /* 4.����1ģ����� */
//    //USART1_Module_Test();
//  
//    /* 5.�ⲿ�ж�ģ����� */
//    //EXTI_Module_Test();
//}

