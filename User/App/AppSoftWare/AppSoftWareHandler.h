/**
 * AppSoftWareHander.h APP������
 * Describtion:
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#ifndef __APP_SOFT_WARE_HANDLER_H__
#define	__APP_SOFT_WARE_HANDLER_H__

#include "stm32f10x.h"
#include "AppSoftWareDriver.h"  //ϵͳִ�������ļ�
#include "myportmacro.h"        //�������ͺ궨��
#include "AppDebugFunc.h"       //���ڵ��Դ�ӡ��Ϣ
#include "leds.h"	        //led����
#include "usart.h"              //uart1����
#include "stm32timer.h"         //��ȡ��ǰϵͳʱ��
#include "mystring.h"           //
#include "AppDebugFunc.h"       //


/*�����¼�������������*/
typedef uint16 EventType;

//--------------------��������ڻ�ִ���¼�--------------------------------------
#define APP_EVENT_GATEWAY_RECVNET         0x0001  /*����ڻ�--��������Э�������¼�*/
#define APP_EVENT_GATEWAY_NETTOEDV        0x0002  /*����ڻ�--�����ն�Э��ת���¼�*/
#define APP_EVENT_GATEWAY_SENDEDV         0x0004  /*����ڻ�--�����ն�Э�������¼�*/
#define APP_EVENT_GATEWAY_RECVEDV         0x0008  /*����ڻ�--�����ն�Э�������¼�*/
#define APP_EVENT_GATEWAY_EDVTONET        0x0010  /*����ڻ�--�ն�����Э��ת���¼�*/
#define APP_EVENT_GATEWAY_SENDNET         0x0020  /*����ڻ�--��������Э�������¼�*/
#define APP_EVENT_GATEWAY_TIMEING         0x0040  /*����ڻ�--���ض�ʱ�¼�*/
#define APP_EVENT_GATEWAY_TEST            0x0080  /*����ڻ�--���ز����¼�*/

#define APP_EVENT_GATEWAY_NETINPUT        0x0100  /*����ڻ�--��ѯ�����������ݰ��¼�*/

//-----------------------��ʱ�¼�ִ��ʱ��--------------------------------------
#define HEART_BEAT_TIME         3000   /*�����¼�ʱ�䣺3000*10msÿ30s����һ��*/
#define APP_INPUT_TMR_INTERVAL  1
#define APP_TCP_TMR_INTERVAL    25     /*TCP �ĵ��������� 250 mstcp_tmr(); */
#define APP_ARP_TMR_INTERVAL    500    /*ARP �ĵ��������� 5s  etharp_tmr();*/


//--------------------------��ʱ�¼�-------------------------------------------
#define APP_T_EVENT_HEARTBEAT    0x0001   /*�������¼�       */


//------------------------����������-------------------------------------------
/*ϵͳ�����ʼ��*/
extern void SoftWareInit(void);

/*ѭ���¼���־λ��λ*/
extern void LoopEventSetBit(EventType event);

/*��ʱѭ���¼���־λ��λ*/
extern void LoopTimeEventSetBit(EventType event);

/*����ڻ�ִ��*/
extern void SoftWareEventInLoop(void);

/*�����ڻ�ִ��*/
//extern void SoftWareTaskInLoop(void);

/*��ʱ�¼��ڻ�ִ��*/
extern void SoftWareTimeingEventInLoop(void);

/*��ʱѭ���¼�ִ�к���*/
extern uint8 SoftTimeingLoopEvent(void);



#endif /* __APP_SOFT_WARE_HANDLER_H__ */
