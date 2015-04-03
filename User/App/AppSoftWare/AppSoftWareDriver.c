/**
 * AppSoftWareDriver.c APP������������
 * Describtion:
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#include "myportmacro.h"
#include "APPDebugFunc.h"
#include "AppSoftWareDriver.h"  //ϵͳִ�������ļ�


/*����ֲ��������*/

//*********************************����ʵ����**********************************

/**
  * @fun    TimeDifference
  * @brief  ʱ���
  * @param  t1
  * @param  t2
  * @retval time difference
  */
uint32 TimeDifference(uint32 t1,uint32 t2)
{
    if(t1>t2) return t1-t2;
    else      return t2-t1;
}


/*����������*/
void HeartBeatHandler(void)
{
    APP_DebugSerialStrOutput("\r\nRun into HeartBeatHandler function !\r\n");
}
