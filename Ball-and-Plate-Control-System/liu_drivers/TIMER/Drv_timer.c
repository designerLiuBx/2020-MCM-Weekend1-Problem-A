#include "timer.h"
volatile u32 g_TimingTick = 0;
volatile u32 g_TimingTickOld = 0;

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!
void dev_SysTick_init(void)
{
        TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
				RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  ///使能TIM3时钟

        /* Time base configuration */
        TIM_TimeBaseStructure.TIM_Period = 65535;               
        TIM_TimeBaseStructure.TIM_Prescaler = 36000-1; 
        TIM_TimeBaseStructure.TIM_ClockDivision =  TIM_CKD_DIV1;    
        TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
        
        TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
        
        TIM_SetCounter(TIM2, 0);

        /* TIM enable counter */
        TIM_Cmd(TIM2, ENABLE);
}
u32 GetTimingTick(void)
{
        return g_TimingTick;
}

void Task_SysTick(void)
{
    u32 temp = TIM_GetCounter(TIM2);

    if (temp > 1000)
    {
		 TIM_SetCounter(TIM2, 0);
     g_TimingTickOld = g_TimingTickOld + temp;
     temp = 0;
    }
    g_TimingTick = g_TimingTickOld + temp;
				
/**********************************保存欧拉角数据*************************/
		switch(CHeck(data_buf))//检查有无数据接收完毕，并返回输出指令
		{
			
			case 0x15:{//加数度数据输出
					Acc[0]=(data_buf[0]<<8)|data_buf[1];
					Acc[1]=(data_buf[2]<<8)|data_buf[3];
					Acc[2]=(data_buf[4]<<8)|data_buf[5];
					send_out(Acc,3,0x15);
		}
			break;
			case 0x25:{//陀螺仪数据输出
					Gyr[0]=(data_buf[0]<<8)|data_buf[1];
					Gyr[1]=(data_buf[2]<<8)|data_buf[3];
					Gyr[2]=(data_buf[4]<<8)|data_buf[5];
				  attitude.pitchV=Gyr[0]*0.01;
				  attitude.rollV=Gyr[1]*0.01;
					send_out(Gyr,3,0x25);
			}
				break;
			case 0x35:{//磁场数据输出
					Mag[0]=(data_buf[0]<<8)|data_buf[1];
					Mag[1]=(data_buf[2]<<8)|data_buf[3];
					Mag[2]=(data_buf[4]<<8)|data_buf[5];
					send_out(Mag,3,0x35);
			}
				break;
			case 0x45:{//欧拉角数据输出
					ROLL=(data_buf[0]<<8)|data_buf[1];   //滚转
					PITCH=(data_buf[2]<<8)|data_buf[3];  //俯仰
					YAW=(data_buf[4]<<8)|data_buf[5];    //航向
					rpy[0]=ROLL;
					rpy[1]=PITCH;
					rpy[2]=YAW;
					//attitude.roll = ROLL-18000;
				  //attitude.roll = (attitude.roll>2000||attitude.roll<-2000)? attitude.roll_pre :attitude.roll;
					attitude.pitch = 0.1*(int)(PITCH*0.1);
					attitude.roll  = 0.1*(int)((ROLL)*0.1);
					attitude.roll  = (attitude.roll>0)? (180-attitude.roll):-(180+attitude.roll);
				
				  //attitude.roll_pre=attitude.roll;
					send_out(rpy,3,0x45);
			}
				break;
			case 0x65:{//四元数数据输出
					Q[0]=(data_buf[0]<<8)|data_buf[1];
					Q[1]=(data_buf[2]<<8)|data_buf[3];
					Q[2]=(data_buf[4]<<8)|data_buf[5];
					Q[3]=(data_buf[6]<<8)|data_buf[7];
					send_out(Q,4,0x65);
			}
				break;
			default:break;
		}
/**************************************************************************/
	
}
	/*
int KEY_QUE=0;
void dsp_cmd(void)
{
	static int stat=1;
    key_scan(0);
  LCD_DisplayChar(15,15,'1',12);
	LCD_DisplayChar(15,27,'2',12);
	LCD_DisplayChar(15,39,'3',12);
	LCD_DisplayChar(15,51,'4',12);
	LCD_DisplayChar(15,63,'5',12);
	LCD_DisplayChar(15,75,'6',12);
	LCD_DisplayChar(15,87,'7',12);
	LCD_DisplayChar(15,99,'8',12);
  LCD_DisplayChar(100,199,'k',12);
	LCD_DisplayChar(112,199,'=',12);
	LCD_DisplayNum(128,199,KEY_QUE,6,12,0);
if(keydown_data==KEY0_DATA)
{
stat--;
if(stat==0)stat=9;
}
if(keydown_data==KEY1_DATA)
{
   stat++;
	if(stat==9)stat=0;
}

if(stat==1)
{
	BRUSH_COLOR=BLUE;
  LCD_DisplayChar(15,15,'1',12);
	BRUSH_COLOR=WHITE;
}
if(stat==2)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,27,'2',12);;
	BRUSH_COLOR=WHITE;
}
if(stat==3)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,39,'3',12);
	BRUSH_COLOR=WHITE;
}
if(stat==4)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,51,'4',12);
	BRUSH_COLOR=WHITE;
}
if(stat==5)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,63,'5',12);
	BRUSH_COLOR=WHITE;
}
if(stat==6)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,75,'6',12);
	BRUSH_COLOR=WHITE;
}
if(stat==7)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,87,'7',12);
	BRUSH_COLOR=WHITE;
}
if(stat==8)
{
	BRUSH_COLOR=BLUE;
	LCD_DisplayChar(15,99,'8',12);
	BRUSH_COLOR=WHITE;
}

if(keydown_data==KEY2_DATA)
{
 KEY_QUE=stat;
}
if(keydown_data==KEY3_DATA)
{
 KEY_Q*UE=0;
}
}
*/