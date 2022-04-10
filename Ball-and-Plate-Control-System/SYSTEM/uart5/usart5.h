#ifndef __USART5_H
#define __USART5_H
//#include "Gen_include.h"
#include "sys.h"
typedef struct 
{
	 double x;        //x����
	 double y;        //y����
	 double Vx;       //x�����ٶ�
	 double Vy;       //y�����ٶ�
}K;
typedef struct 
{
   char ch;             //���ܵ����ַ�
	 char str[100];        //�����ַ���
	 char x[1000];          //x������ܷ���
	 char y[100];          //y������ܷ���
	 char Vx[100];         //�ٶ�x������ܷ���
	 char Vy[100];         //�ٶ�y������ܷ���
}USART_RV;
int printf_s(const char *str,...);
static unsigned long m_pow(int x,int y);
void putchar_s(const char ch);
void put_s(const char *str);
char *get_s(char *p);
void uart5_init(u32 bound);
#endif
