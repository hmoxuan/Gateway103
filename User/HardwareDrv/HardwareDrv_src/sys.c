/**
 * sys.c file for STM32F103.
 * Describtion: The underlying hardware related setting function
 * Author: qinfei 2015.03.26
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#include "sys.h"
 
void NVIC_Configuration(void)
{
  /* ����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}