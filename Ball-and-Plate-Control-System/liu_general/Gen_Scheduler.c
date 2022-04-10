#include "Gen_Scheduler.h"
#define ARRAYSIZE(a) (sizeof(a) / sizeof((a)[0]))

u8 x=0;
double last_y=0,last_x=0;
double vY=0,vX=0;
int time=0;
static void Loop_300Hz(void)	//10ms执行一次
{
/*********************************************************/
	static double v_y[4]={0};
	static double v_x[4]={0};

	v_y[0]=(k.y-last_y);
  last_y=k.y;
	vY=(v_y[0]+v_y[1]+v_y[2]+v_y[3])/4;
	for(int i=1;i<=3;i++) v_y[i]=v_y[i-1];
	
	v_x[0]=(k.x-last_x);
  last_x=k.x;
	vX=(v_x[0]+v_x[1]+v_x[2]+v_x[3])/4;
	for(int i=1;i<=3;i++) v_x[i]=v_x[i-1];
/**********************************************************/
	Main_Contriller();  				  //主控制器
}

static void Loop_30Hz(void)	//10ms执行一次
{
  LCD_DisplayChar(15,270,'x',12);
	LCD_DisplayChar(27,270,'=',12);
	LCD_DisplayNum(39,270,k.x,6,12,0);
	
	LCD_DisplayChar(91,270,'y',12);
	LCD_DisplayChar(103,270,'=',12);
	LCD_DisplayNum(114,270,k.y,6,12,0);
  //disp_show();
}
static void Loop_50Hz(void)	//20ms执行一次
{
/***************************上位机发送***************************/
	static unsigned char i;          //计数变量
	static unsigned char Send_Count; //串口需要发送的数据个数
	DataScope_Get_Channel_Data(AllPidParameter.parameterPitch_p.output02, 1 );
  DataScope_Get_Channel_Data(AllPidParameter.parameterPitch_v.output02, 2 );

	DataScope_Get_Channel_Data(AllPidParameter.parameterPitch_p.error,    3 );
  DataScope_Get_Channel_Data(AllPidParameter.parameterRoll_p.error,     4 );
	
	DataScope_Get_Channel_Data(AllPidParameter.parameterPitch_p.output02, 5 );
  DataScope_Get_Channel_Data(AllPidParameter.parameterRoll_v.output02,  6 );
	DataScope_Get_Channel_Data(vY,                                        7 );
  DataScope_Get_Channel_Data(vX,                                        8 );	
	Send_Count = DataScope_Data_Generate(10);
	for( i = 0 ; i < Send_Count; i++) 
	{
		while((USART2->SR&0X40)==0);  
		USART2->DR = DataScope_OutPut_Buffer[i]; 
	}
/*****************************************************************/	
}

static void Loop_500Hz(void)	//200ms执行一次
{
	LED1=!LED1;
}	

//系统任务配置，创建不同执行频率的“线程”
static sched_task_t sched_tasks[] = 
{
	{Task_SysTick,    0, 0},
	{Loop_30Hz,      30, 0},
	{Loop_50Hz,      50, 0},
	{Loop_300Hz,    300, 0},
	{Loop_500Hz,    500, 0},
};
void Scheduler_Run(void)
{
	u32 index = 0;
	//初始化任务表
  for (index = 0; index < ARRAYSIZE(sched_tasks); index++)
	{
		if (sched_tasks[index].uNextTick <= GetTimingTick())
		{	
     sched_tasks[index].uNextTick += sched_tasks[index].uLenTick;
     sched_tasks[index].task_func();
		}
  }
}
