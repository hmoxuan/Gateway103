/**
 * usart.c file for STM32F103.
 * Describtion: usart control module
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */
#include "sys.h"
#include "delay.h"
#include "leds.h"
#include "usart.h"

/* usart1 ���ջ������63���ֽ�,ĩ�ֽ�Ϊ���з� */
u8 USART_RX_BUF[64];

/**
 * ����״̬
 * bit7��������ɱ�־
 * bit6�����յ�0x0d
 * bit5~0�����յ�����Ч�ֽ���Ŀ
 */
u8 USART_RX_STA=0;/* ����״̬��� */

/*
 * ��������fputc
 * ����  ���ض���c�⺯��printf��USART1
 * ����  ����
 * ���  ����
 * ����  ����printf����
 */
int fputc(int ch, FILE *f)
{
	/* ��printf���ݷ������� */
	USART_SendData(USART1, (unsigned char) ch);
	while (!(USART1->SR & USART_FLAG_TXE));
	
	return (ch);
}

void uart1_init(u32 bound)
{
    /* GPIO�˿����� */
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
     
    /* config USART1 clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
    
    /* USART1_TX  PA.9 */
    /* Configure USART1 Tx (PA.09) as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* USART1_RX  PA.10 */
    /* Configure USART1 Rx (PA.10) as input floating */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);  

    /* Usart1 NVIC ���� */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;/* IRQͨ��ʹ�� */
    NVIC_Init(&NVIC_InitStructure);/* ����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���USART1 */

    /* USART ��ʼ������ */
    USART_InitStructure.USART_BaudRate = bound;/* һ������Ϊ9600; */
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    
    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);/* �����ж� */

    USART_Cmd(USART1, ENABLE);/* ʹ�ܴ��� */ 
}

/*����1�жϷ������ */
void USART1_IRQHandler(void)                	
{
    u8 Res;
    
    /* �����ж�(���յ������ݱ�����0x0d 0x0a��β) */
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
        Res=USART_ReceiveData(USART1);/* (USART1->DR);��ȡ���յ������� */
        
        if((USART_RX_STA&0x80)==0)/* ����δ��� */
        {
            /*0X0D-0X0A��ʾ�س���*/
            if(USART_RX_STA&0x40)/* ���յ���0x0d */
            {
                if(Res!=0x0a)
                  USART_RX_STA=0;/* ���մ���,���¿�ʼ */
                else 
                  USART_RX_STA|=0x80;/* ��������� */
            }
            else /* ��û�յ�0X0D */
            {	
                if(Res==0x0d)
                {
                  USART_RX_STA|=0x40;
                }
                else
                {
                    USART_RX_BUF[USART_RX_STA&0X3F]=Res ;
                    USART_RX_STA++;
                    if(USART_RX_STA>63)
                      USART_RX_STA=0;/*�������ݴ���,���¿�ʼ����*/	  
                }		 
            }
        }   		 
     } 
} 


/*����1ģ����Գ��� */
void USART1_Module_Test(void)
{
    u8 t;
    u8 len;	
    static u16 times=0;/*����Ϊstatic���������´ε��ñ�֤times�����ϴε�ֵ*/
    
    /*usart1�����������*/
    if(USART_RX_STA&0x80)/*����״̬���*/
    {					   
        len=USART_RX_STA&0x3f;/*�õ��˴ν��յ������ݳ���*/
        printf("\n�����͵���ϢΪ:\n");
        for(t=0;t<len;t++)
        {
            USART1->DR=USART_RX_BUF[t];
            while((USART1->SR&0X40)==0);/*�ȴ����ͽ���*/
        }
        printf("\n\n");/*���뻻��*/
        printf("\n�뷢��������Ϣ!\n");
        USART_RX_STA=0;/*����״̬�����0*/
    }
    /*usart1��������δ���*/
    else
    {
        times++;
        if(times%5000==0)
        {
            printf("\nMiniSTM32������ ����ʵ��\n");
            printf("����ԭ��@ALIENTEK\n\n\n");
        }
        if(times%200==0)
          printf("����������,�Իس�������\n");  
        if(times%30==0)
          LED0=!LED0;/* ��˸LED,��ʾϵͳ��������. */
        delay_ms(10);   
    }
}