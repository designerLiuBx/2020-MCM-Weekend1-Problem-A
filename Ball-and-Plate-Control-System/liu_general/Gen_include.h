#ifndef __GINCLUDE_H
#define __GINCLUDE_H	 
#include "stm32f4xx.h"
#include "usart.h"
#include "usart2.h"
#include "usart3.h"
#include "delay.h"
#include "init.h"
#include "beep.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "pwm.h"
#include "lcd_hz.h"
#include "w25qxx.h"
#include "timer.h"
#include "usmart.h"
#include "DataScope_DP.h"
#include "Gen_Structconfig.h"
#include "Gen_Scheduler.h"
#include "Sen_gy953.h"
#include "spi.h"
#include "ALG_dsp.h"
#include "ALG_pid.h"
#include "ALG_control.h"
#include "usart5.h"
//=======================================
/**************参数定义*****************/

#define DPI 199
#define T 0.06
#define PWMX_BASE  1500
#define PWMY_BASE  1390    //pitch
	extern _flag flag;
	extern _attitude attitude;
	extern _basePoint basePoint;
	extern _ballPoint ballPoint;
  extern _Target_Position Target_Position;
	
	extern _AllPidParameter AllPidParameter;
	
	extern int Pwm1,Pwm2;
	extern double angleTestp,angleTestr;
	extern double kpTest,tiTest,tdTest,limitingMaxTest,limitingMinTest;
	
	extern int pwmPitch;
	extern int pwmRoll;
	extern int K_p,T_i,T_d;
	extern uint8_t  data_buf[9];
	extern int16_t  ROLL,PITCH,YAW;
	extern int16_t  rpy[3],Acc[3],Gyr[3],Mag[3],Q[4];
	extern int p;
	extern K  k;
	extern int last_kx,vx;
	extern double last_y,last_X;
	extern double vY,vX;
	extern double V0;
	extern double V1;
/***************************************/

//=======================================
/***************中断优先级******************/
#define NVIC_GROUP NVIC_PriorityGroup_3		//中断分组选择

#define NVIC_TIME_P       0					//定时器中断配置，暂未使用
#define NVIC_TIME_S       0

#define NVIC_UART1_P			3			//串口1中断配置 //gps
#define NVIC_UART1_S			0
/***********************************************/

#endif
