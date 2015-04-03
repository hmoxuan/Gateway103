/**
 * keys.c file for STM32F103.
 * Describtion: key control module
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#include "sys.h"
#include "leds.h" 
#include "beep.h" 
#include "delay.h"
#include "keys.h" 

/* ����ɨ�躯�� */	
static u8 KEY_Scan(u8 mode);

/* IO��ʼ�� */
void KEY_Init(void) 
{ 
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTEʱ��
        
    /*��ʼ��KEY0-->GPIOE.2,KEY1-->GPIOE.3,KEY2-->GPIOE.4�������� */

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//PE2~4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4

    /* ��ʼ�� WK_UP-->GPIOA.0 �������� */
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
    GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
}

/**
 * ����������
 * ���ذ���ֵ
 * mode:0,��֧��������;1,֧��������;
 * 0��û���κΰ�������
 * 1��KEY0����
 * 2��KEY1����
 * 3��KEY2����
 * 4��KEY3���� WK_UP
 * �˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
 */
static u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||KEY3==1))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY0==0)return KEY_RIGHT;
		else if(KEY1==0)return KEY_DOWN;
		else if(KEY2==0)return KEY_LEFT;
		else if(KEY3==1)return KEY_UP;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&KEY3==0)key_up=1; 	    
 	return 0;// �ް�������
}

/* LEDSģ����� */
void KEY_Module_Test(void)
{
  u8 t;
  LED0=0;//�ȵ������
  
  while(1)
  {
      t=KEY_Scan(0);//�õ���ֵ
      if(t)
      {						   
          switch(t)
          {				 
              case KEY_UP://���Ʒ�����
                      BEEP=!BEEP;
                      break;
              case KEY_LEFT://����LED0��ת
                      LED0=!LED0;
                      break;
              case KEY_DOWN://����LED1��ת	 
                      LED1=!LED1;
                      break;
              case KEY_RIGHT://ͬʱ����LED0,LED1��ת 
                      LED0=!LED0;
                      LED1=!LED1;
                      break;  
              default:   break;              
          }
      }else delay_ms(10); 
  }	 
}