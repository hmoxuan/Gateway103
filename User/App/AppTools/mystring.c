/**
 * mystring.c file for STM32F103.
 * Describtion: �ַ�����ز���������
 * Author: qinfei 2015.04.02
 * Version: GatewayV1.0
 * Support:qf.200806@163.com
 */

#include "mystring.h"
#include "myportmacro.h"
#include <string.h>
#include <stdio.h>

static uint8 dest[100]="adajlngijnlfahogjlhs";
static uint8 src[20]="1234567891234657891";

/*�ַ������Ժ���*/
void StringTest(void)
{
	strcat_oppo(dest,src);
	printf("%s\n",dest);
}


/**
  *	@fun	strcat_oppo
  * @brief  ��src�ַ������ӵ�dest�ַ�����ǰ��
  * @param  dest	:ָ��Ŀ���ַ�����ָ��
  * @param  src		:ָ��Դ�ַ�����ָ��
  * @retval None
  */
void strcat_oppo(uint8 *dest,const uint8 *src)
{
	uint16	dlength,slength;
	dlength=(uint16)strlen((const char*)dest);
	slength=(uint16)strlen((const char*)src);
	StrInvertSeq(dlength,dest);
	StrInvertSeq(slength,(uint8 *)src);
	strcat((char*)dest,(const char*)src);
	StrInvertSeq(dlength+slength,dest);
}

/**
  *	@fun	clcstr
  * @brief  �ַ������
  * @param  src		:ָ��Դ�ַ�����ָ��
  * @param  length	:�ַ�������
  * @retval None
  */
void clcstr(uint8 *src,uint16 length)
{
	for(;length>0;length--)
		src[length-1]='\0';
}

/**
  *	@fun	IntToStr
  * @brief  �޷�������ת��Ϊ�ַ���
  * @param  num		:�ַ�������
  * @param  str		:ָ���ַ�����ָ��
  * @retval str		:�����ַ�����ָ��
  */
uint8 *IntToStr(uint16 num,uint8 *str)
{
	uint8 i=0;
	while(num){
		str[i]=num%10+'0';
		num/=10;
		i++;
	}
	str[i]='\0';
	StrInvertSeq(i,str);
	return str;
}


/**
  *	@fun	LongIntToStr
  * @brief  �޷��ų�����ת��Ϊ�ַ���
  * @param  num		:�ַ�������
  * @param  str		:ָ���ַ�����ָ��
  * @retval str		:�����ַ�����ָ��
  */
uint8 *LongIntToStr(uint32 num,uint8 *str)
{
	uint16 i=0;
	while(num){
		str[i]=num%10+'0';
		num/=10;
		i++;
	}
	str[i]='\0';
	StrInvertSeq(i,str);
	return str;
}

/**
  *	@fun	IntToHexStr
  * @brief  �޷�������ת��Ϊ16���Ʊ�ʾ���ַ���
  * @param  num		:Ҫ����ת������ֵ����
  * @param  str		:ָ��2�ֽ��ַ�����ָ��
  * @retval str		:����2�ֽ��ַ�����ָ��
  *	@date	2014/6/6
  */
uint8 *IntToHexStr(uint8 num,uint8 *str)
{
	uint8	i;
	uint8	tdu[2];
	for(i=0,tdu[0]=num/0x10,tdu[1]=num%0x10;i<2;i++)
		str[i]=tdu[i]/10?tdu[i]%10+'A':tdu[i]%10+'0';
	return str;
}

/**
  *	@fun	StrInvertSeq
  * @brief  �ַ���������������漰�ַ���������־
  * @param  strnum	:�ַ�������
  * @param  str		:ָ���ַ�����ָ��
  * @retval None
  */
void StrInvertSeq(uint16 strnum,uint8 *str)
{
	uint8  c;
	uint16 i=0;
	uint16 num=strnum/2;
	for(strnum--;i<num;i++,strnum--){
		c=str[i];
		str[i]=str[strnum];
		str[strnum]=c;
	}
}

/**
  *	@fun	BinToHex_Str
  * @brief  �������ƴ�ת��Ϊ16���Ƶ��ַ���
  * @param  dest	:ָ��װ���ַ�����ָ��
  * @param  src		:ָ������ƴ���ָ��
  * @param  length	:�����ƴ��ĳ���
  * @retval dest	:�����ַ�����ָ��
  *	@date	2014/6/6
  */
uint8 *BinToHex_Str(uint8 *dest,const uint8 *src,uint16 length)
{
	uint16	i;
	for(i=0;i<length;i++)
		IntToHexStr(src[i],&dest[i*2]);
	return dest;
}

/**
  *	@fun	_strrchr
  * @brief  ��λ�ַ����������ֵ�ָ���ַ�
  * @param  str		:ָ���ַ�����ָ��
  * @param  ch		:�ַ�
  * @retval uint16	:����ֵ
  */
char *_strrchr(const char *str,int ch)
{
	char *start=(char *)str;
	while(*str++); /*get the end of the string*/
	while(--str != start && *str != (char)ch); /**/
	if(*str == (char)ch)
		return((char *)str);
	return NULL;
}

/**
  *	@fun	_strncpy
  * @brief  ����num���ַ�����dest
  * @param  dest	:ָ��װ���ַ�����ָ��
  * @param  src		:ָ��Դ�ַ�����ָ��
  * @param  length	:�ַ����ĳ���
  * @retval dest	:�����ַ�����ָ��
  *	@date	2014/7/19
  */
uint8 *_strncpy(uint8 *dest,const uint8 *src,uint16 length)
{
	uint16	i;
	for(i=0;i<length;i++)	dest[i]=src[i];
	return dest;
}

