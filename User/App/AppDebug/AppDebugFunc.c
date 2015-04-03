/**
 * AppDebugFunc.c file for STM32F103.
 * Describtion: Debug file
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

/*����ʹ�õĺ�����*/
#include "AppDebugCfg.h"
#include "AppDebugFunc.h"
#include "mystring.h"     //
#include "myportmacro.h"  //�������ͺ궨��
#include <stdio.h>

/*���Դ�ӡ�ַ������*/
void APP_DebugSerialStrOutput(const uint8 *str)
{
    #if (APP_DEBUG_STATE)
    printf("%s",str);
    #else
    ;
    #endif
}
