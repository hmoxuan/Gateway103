/**
 * AppSoftWareHander.c APP������
 * Describtion:
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#include "AppSoftWareHandler.h"


/*ѭ���¼�ִ�б�־*/
uint16  LoopEvents=0x0000;

/*ѭ���¼�ִ�б�־�ݴ�*/
uint16  LoopEventstmp=0x0000;//���жϴ������лᱻ�޸�

/*��ʱѭ���¼�ִ�б�־*/
static uint16  LoopTimeEvents=0x0000;

/*��ʱѭ���¼�ִ�б�־�ݴ�*/
static uint16  LoopTimeEventstmp=0x0000;


//*********************************����ʵ����**********************************
/*
 * ��������ϵͳ�����ʼ��
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
void SoftWareInit(void)
{	
    APP_DebugSerialStrOutput("\r\nHandler SoftWareInit function ! \r\n");
    
    /*������ѯ�����������ݰ��¼���־ */  
    //LoopEventSetBit(APP_EVENT_GATEWAY_NETINPUT);
    
    /*��������Э�������¼�*/
    LoopEventSetBit(APP_EVENT_GATEWAY_RECVNET);
}

/**
  * @fun    LoopEventSetBit
  * @brief  ѭ���¼���־λ��λ
  * @param  None
  * @retval None
  */
void LoopEventSetBit(EventType event)
{
    LoopEventstmp|=event;
}

/**
  * @fun    LoopTimeEventSetBit
  * @brief  ��ʱѭ���¼���־λ��λ
  * @param  None
  * @retval None
  */
void LoopTimeEventSetBit(EventType event)
{
    LoopTimeEventstmp|=event;
}


/**
  * @fun    SoftWareEventInLoop
  * @brief  �¼��ڻ�ִ��
  * @param  None
  * @retval None
  */
void SoftWareEventInLoop(void)
{
    uint8  hdlstate=0;  /*����״̬*/
    
//*******************����NET->GATEWAY->�ն�*************************************/
    //----------------------------------/*����ڻ�--��������Э�������¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_RECVNET){
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_RECVNET!\r\n");
        
        LoopEventSetBit(APP_EVENT_GATEWAY_NETTOEDV);/*��λ�����ն�Э��ת���¼�*/
        hdlstate=1;
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_RECVNET;
            hdlstate ^= hdlstate;
        }
    }
    
    //----------------------------------/*����ڻ�--�����ն�Э��ת���¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_NETTOEDV){
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_NETTOEDV!\r\n");
        
        LoopEventSetBit(APP_EVENT_GATEWAY_SENDEDV);/*��λ���ڴ����¼�*/
        hdlstate=1;
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_NETTOEDV;
            hdlstate ^= hdlstate;
        }
    }
    
    //----------------------------------/*����ڻ�--�����ն�Э�������¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_SENDEDV){
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_SENDEDV!\r\n");
        
        //LoopEventSetBit();/*�������������¼�*/
        hdlstate=1;
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_SENDEDV;
            hdlstate ^= hdlstate;
        } 
    }

//*******************�ն�->GATEWAY->����NET*************************************/    
    //----------------------------------/*����ڻ�--�����ն�Э�������¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_RECVEDV){
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_RECVEDV!\r\n");
        
        //APP_SerialRecvHandler();/*���ڽ��մ����¼�*/

        LoopEventSetBit(APP_EVENT_GATEWAY_EDVTONET);/*��λ�ն�����Э��ת���¼�*/
        hdlstate=1;
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_RECVEDV;
            hdlstate ^= hdlstate;
        }
    }
    
    //----------------------------------/*����ڻ�--�ն�����Э��ת���¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_EDVTONET){
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_EDVTONET!\r\n");
         
        LoopEventSetBit(APP_EVENT_GATEWAY_SENDNET);/*��λ�ն�����Э��ת���¼�*/
        hdlstate=1;
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_EDVTONET;
            hdlstate ^= hdlstate;
        }
    }
    
    //----------------------------------/*����ڻ�--��������Э�������¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_SENDNET){
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_SENDNET!\r\n");
        
        //LoopEventSetBit();/*�������������¼�*/
        hdlstate=1;
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_SENDNET;
            hdlstate ^= hdlstate;
        }
    }
    
//*******************���ض�ʱ**************************************************/     
    //----------------------------------/*����ڻ����ض�ʱ�¼�*/
    if(LoopEvents & APP_EVENT_GATEWAY_TIMEING){
        APP_DebugSerialStrOutput("\r\n Gateway timed events in SoftWareEventInLoop!\r\n");
        APP_DebugSerialStrOutput("\r\nAPP_EVENT_GATEWAY_TIMEING!\r\n");
        
        APP_DebugSerialStrOutput("\r\n Handler SoftTimeingLoopEvent Function!\r\n");
        hdlstate=SoftTimeingLoopEvent();/*��ʱѭ���¼�ִ�к���*/
        if(hdlstate){
            LoopEvents ^= APP_EVENT_GATEWAY_TIMEING;
            hdlstate ^= hdlstate;
        }
    }
    
    
//*****************************************************************************/      
    LoopEvents |= LoopEventstmp;
    LoopEventstmp ^= LoopEventstmp;
    
//*****************************************************************************/         
    //LwIP_Periodic_Handle();//��ѯ�Ƿ���յ�����
}

/**
  * @fun    SoftWareTimeingEventInLoop
  * @brief  ��ʱ�¼��ڻ�ִ��
  * @param  None
  * @retval None
  */
void SoftWareTimeingEventInLoop(void)
{
    static uint32 HeartBeatLt=0; /*���������¼���һ��״̬��ʱ�� */
 
    static uint8  HeartBeatLtNowtimeStr[10];//��ӡ������ǰʱ��
    uint32  newTime=0;//��Χ��0-4294967295(4 Bytes)
    newTime=GetSystemNowtime();/*��õ�ǰ����ʱ��*/  
    
    //------------------------------------------------------------------------
    //********�����������¼�***************************************************
    if(TimeDifference(newTime,HeartBeatLt)>=HEART_BEAT_TIME){
        HeartBeatLt=newTime;
        {//�����������ǰ�������ڵ�ʱ�䡣
          LongIntToStr(HeartBeatLt,HeartBeatLtNowtimeStr);//��������ת���ַ���
          APP_DebugSerialStrOutput("\r\nHeartBeatLt Nowtime=");   
          APP_DebugSerialStrOutput(HeartBeatLtNowtimeStr);//�����ǰʱ��
          APP_DebugSerialStrOutput("\r\n");//�س�����     
        }
        APP_DebugSerialStrOutput("\r\n Gateway heartbeat time arrived !\r\n");
       
        LoopEventSetBit(APP_EVENT_GATEWAY_TIMEING); /*��λ����ڻ����ض�ʱ�¼�*/
        APP_DebugSerialStrOutput("\r\n Set Gateway timed events into SoftWareEventInLoop!\r\n");
        
        LoopTimeEventSetBit(APP_T_EVENT_HEARTBEAT);/*��λ�������¼�*/
        APP_DebugSerialStrOutput("\r\n Set Gateway heartbeat timed events into SoftTimeingLoopEvent!\r\n");
    }
    
    LoopTimeEvents|=LoopTimeEventstmp;
    LoopTimeEventstmp^=LoopTimeEventstmp;
}


/**
  * @fun    SoftTimeingLoopEvent
  * @brief  ��ʱѭ���¼�ִ�к���
  * @param  None
  * @retval state of handle event
  */
uint8 SoftTimeingLoopEvent(void)
{
    uint8 state=0;
    uint8 hdlstate=0;
    
    //------------------------------------------------------------------------
    //********�����������¼�***************************************************
    if(LoopTimeEvents & APP_T_EVENT_HEARTBEAT){
        APP_DebugSerialStrOutput("\r\nAPP_T_EVENT_HEARTBEAT!\r\n");
        HeartBeatHandler();
      
        hdlstate=1;
        if(hdlstate){
            LoopTimeEvents ^= APP_T_EVENT_HEARTBEAT;
            hdlstate ^= hdlstate;
        }
    }
    
   
    if(!LoopTimeEvents) state=1;
    return state;
}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
