#ifndef __USART5_H
#define __USART5_H
//#include "Gen_include.h"
#include "sys.h"
typedef struct 
{
	 double x;        //x坐标
	 double y;        //y坐标
	 double Vx;       //x方向速度
	 double Vy;       //y方向速度
}K;
typedef struct 
{
   char ch;             //接受单个字符
	 char str[100];        //处理字符串
	 char x[1000];          //x坐标接受分离
	 char y[100];          //y坐标接受分离
	 char Vx[100];         //速度x坐标接受分离
	 char Vy[100];         //速度y坐标接受分离
}USART_RV;
int printf_s(const char *str,...);
static unsigned long m_pow(int x,int y);
void putchar_s(const char ch);
void put_s(const char *str);
char *get_s(char *p);
void uart5_init(u32 bound);
#endif
