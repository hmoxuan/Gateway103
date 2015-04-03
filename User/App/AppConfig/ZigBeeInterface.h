/**
 * ZigBeeInterface.h file for STM32F103.
 * Describtion: ������ZigBeeЭ�����ӿڵ����ݽṹ
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#ifndef __ZIGBEE_INTERFACE_H__
#define __ZIGBEE_INTERFACE_H__
#include "myportmacro.h"

/**
  * @brief 	�������
  * @brief 	�ŵ������书�ʡ�panID
  */
typedef struct{
    uint8  Channel;         //�ŵ�
    uint8  Txpower;         //���书��
    uint16 panID;           //panID
}NetParamt_t;

/**
  * @brief 	�ڵ���Ϣ
  * @brief 	�ڵ����͡��ڵ�Ӧ������
  */
typedef struct {
    uint8  NodeType;		//NodeType
    uint8  NodeAppType;     //Node App Type
    uint8  Reserved[2];		//����λ-����ʹ��
}NodeInfo_t;

/**
  * @brief ���ڵ���Ϣ
  * @brief ���ڵ����͡����ڵ�Ӧ�����͡����ڵ�̵�ַ
  */
typedef struct {
    uint8  pNodeType;		//���ڵ�����
    uint8  pNodeAppType;	//���ڵ�Ӧ������
    uint16 pNwkSrc;			//���ڵ�Nwk
}pNodeInfo_t;

/**
  * @brief �󶨿��ƺ͹�����ز���
  * @brief �̵�ַ��clusterID
  */
typedef struct{
    uint16 NwkDest;
    uint16 ClusterID;
}BindCtrl_t;

/**
  * @brief �Ʋ����ͱ���
  */
typedef struct
{
    uint8  CtrlMode;        //���ƵƵ�ģʽ: 0-˲����� ; 1-�𽥱�����
    uint8  CtrlSelect;      //��ůLEDѡ��: 0-ů��LED(P17Ĭ��) ; 1-���LED(P16��ѡ);
    uint8  CtrlVal;         //���ƵƵ�ֵ
    uint8  Reserved;        //����λ-������Ϊ���ȵ���
}LState_t;

/**
  * @brief ���������ͱ���
  */
typedef struct{
    uint8  CtrlVal;         //���ƵƵ�ģʽ: (val=100)������0x01��(val=0)������0x02��(val=50)����ͣ0x03��
    uint8  Reserved[3];     //����λ-����ʹ�� 
}Curtain_t; 

/**
  * @brief �ʵƲ����ͱ���
  * @brief �����ƽṹ�����չ
  */
typedef struct{
    uint8  Red;			//��ɫֵ
    uint8  Green;		//��ɫֵ
    uint8  Blue;		//��ɫֵ
    uint8  Reserved;		//����λ-������Ϊ���ȵ���
}ColorL_t;

/**
  * @brief ���������ͱ���
  * @brief �����ƽṹ�����չ
  */
typedef struct{
    uint8  Reserved[4];		//����λ-
}Socket_t;

/**
  * @brief ��Ҫ���ݵ���Ϣ�������ڵ���Ϣ�͵�ַ��Ϣ�ȣ�����Ϊ4���ֽ�
  */
typedef union{
    NetParamt_t NetParamt;  //�������
    NodeInfo_t  NodeInfo;   //�ڵ���Ϣ
    pNodeInfo_t pNodeInfo;  //���ڵ���Ϣ
    BindCtrl_t  BindCtrl;   //�󶨿��ƺ͹�����ز���
    LState_t    LState;     //�Ʋ����ͱ���
    Curtain_t   Curtain;    //���������ͱ���
    ColorL_t    ColorL;     //�ʵƲ����ͱ���
    Socket_t    Socket;     //����
}UnionInfo_t;

/**
  * @brief �ڵ������Ϣ & mac��ַ��Ϣ
  */
typedef union{
    struct{
        UnionInfo_t info;
        uint8       Reserved[4];
    }U_info;
    uint8           mac[8];
}UnionInfo_mac;

/**
  * @brief �ڵ���Ϣ
  */
typedef struct{
  UnionInfo_mac Info_mac;     /*��Ҫ���ݵ���Ϣ�������ڵ���Ϣ�͵�ַ��Ϣ��*/
  uint16        NwkDest;  	  /*NwkDestĿ�ĵ�ַ*/
}SendNode_t;

/**
  * @brief ���ͺͽ��յ�������ݽṹ
  * @brief ����ʹ�õ�12�ֽ����ݽṹ
  */
typedef struct{
  uint8            CMD;       /*����Command    */
  uint8            ClusterID; /*ClusterID Flag */
  SendNode_t       SendNode;  /*�ڵ���Ϣ       */
}Send_Recv_CMDA_t;

//-----------------------------------------------------------------------------

/*����zigbee�����ڵ����ݽṹ*/
typedef UnionInfo_mac ZigbeeData_t;

//-----------------------------------------------------------------------------

/**
  * @brief Zigbee���������нڵ�Ľڵ�Ӧ�����Ͷ���
  */
#define NODE_APP_TYPE_LIGHT             0x01  //������
#define NODE_APP_TYPE_CLIGHT            0x02  //�ʵ�����
#define NODE_APP_TYPE_CURTAIN           0x03  //��������
#define NODE_APP_TYPE_GETEWAY           0x04  //��������


#endif /*__ZIGBEE_INTERFACE_H__*/
