#include "init.h"
#include "Gen_include.h"
u8 All_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_GROUP);		//中断优先级组别设置
	delay_init(168);
	uart_init(115200);
	uart5_init(115200);
	LCD_Init();										//LCD 显示初始化
	TIM3_PWM_Init(20000-1, 84-1);	//TIM3 PWM 输出	初始化 ()
	BEEP_Init();	
	LED_Init();	
	KEY_Init();
	SPI1_Init();
	usmart_dev.init(84); 					//初始化USMART			
	delay_ms(100);
	BRUSH_COLOR=WHITE;      //设置画笔颜色为红色
	BACK_COLOR=BLACK;
  W25QXX_Init();			//W25QXX初始化
  LCD_Clear(BLACK);	
	uart2_init(115200);
	
/*	Set_pidParv_pitch_p( 10.925,  1.30,    0.0,   0,0);
	Set_pidPar_roll_p(   10.9265	, 1.10,    0.00013000,   0,0);*/
/*	Set_pidParv_pitch_p( 3.425,  0,    0,   3,0);
	Set_pidPar_roll_p(   3.4265	, 0,    0 ,   3,0);*/
/*Set_pidPar_pitch_v(  14.433	    ,      50,    0.88564,   0,0);
	Set_pidPar_roll_v(   14.433	  ,       0,   0.88564,   0,0); */
 // Set_pidParv_pitch_p(0.187, 500.0, 0.02,   0,0);
	//Set_pidPar_roll_p(  0.1734, 3.09,   0.00009,   0,0);
//  Set_pidPar_roll_p(0.187, 500.0, 0.02,   0,0);

	//Set_pidPar_pitch_v(15.6,  0, 0.02 , 6, -6);
	//Set_pidPar_roll_v( 11.6	, 0, 0.00002 , 6, -6); 
	//Set_pidPar_roll_v( 15.6,  0, 0.02 , 6, -6); 
	
	
  Set_pidParv_pitch_p(0.11374, 0.2873, 0.0004,   0,0);
	Set_pidPar_roll_p(  0.09, 0.2819,   0.0004,   0,0);
	//Set_pidPar_pitch_v(16	, 0, 0.00066 , 6, -6); 
  //Set_pidPar_pitch_v(10	, 50, 0.00068 , 6, -6);
	Set_pidPar_pitch_v(10	,  50, 0.0006 , 6, -6);
	Set_pidPar_roll_v( 11.4	, 0, 0.00002 , 6, -6); 
	Set_pidPar_pitch_v(15.6,  0, 0.02 , 6, -6);
	//Set_pidPar_roll_v( 11.6	, 0, 0.00002 , 6, -6); 
	Set_pidPar_roll_v( 15.6,  0, 0.02 , 6, -6); 
  Target_Position.oneCoreY=172;
	Target_Position.oneCoreX=31;
	
	Target_Position.twoCoreY=100;
	Target_Position.twoCoreX=31+21;
	
	Target_Position.threeCoreY=29;
	Target_Position.threeCoreX=31;
/********************************************************/	
	Target_Position.fourCoreY=171;
	Target_Position.fourCoreX=100;
	
	Target_Position.fiveCoreY=101;
	Target_Position.fiveCoreX=103;
	
	Target_Position.sixCoreY=27;
	Target_Position.sixCoreX=103;
/*******************************************************/
	Target_Position.sevenCoreY=171;
	Target_Position.sevenCoreX=169;
	
	Target_Position.eightCoreY=102;
	Target_Position.eightCoreX=173;
	
	Target_Position.nineCoreY=28;
	Target_Position.nineCoreX=173;

	return 1;
}

void Set_angle(double angleTestp1, double angleTestr1)
{
	angleTestp = angleTestp1;
	angleTestr = angleTestr1;
}
void Set_pidParv_pitch_p(double kp, double ti, double td , double limitingMax, double limitingMin)
{
	AllPidParameter.parameterPitch_p.k_p = kp;
	AllPidParameter.parameterPitch_p.k_i = ti;
	AllPidParameter.parameterPitch_p.k_d = td;

	AllPidParameter.parameterPitch_p.limitingMax = 6;
	AllPidParameter.parameterPitch_p.limitingMin = -6;
}
void Set_pidPar_pitch_v(double kp, double ti, double td , double limitingMax, double limitingMin)
{
	AllPidParameter.parameterPitch_v.k_p = kp;
	AllPidParameter.parameterPitch_v.k_i = ti;
	AllPidParameter.parameterPitch_v.k_d = td;
	AllPidParameter.parameterPitch_v.limitingMax = 6;
	AllPidParameter.parameterPitch_v.limitingMin = -6;
}
void Set_pidPar_roll_p(double kp, double ti, double td , double limitingMax, double limitingMin)
{
	AllPidParameter.parameterRoll_p.k_p = kp;
	AllPidParameter.parameterRoll_p.k_i = ti;
	AllPidParameter.parameterRoll_p.k_d = td;
	AllPidParameter.parameterRoll_p.limitingMax = limitingMax;
	AllPidParameter.parameterRoll_p.limitingMin = limitingMin;
}
void Set_pidPar_roll_v(double kp, double ti, double td , double limitingMax, double limitingMin)
{
	AllPidParameter.parameterRoll_v.k_p = kp;
	AllPidParameter.parameterRoll_v.k_i = ti;
	AllPidParameter.parameterRoll_v.k_d = td;
	AllPidParameter.parameterRoll_v.limitingMax = limitingMax;
	AllPidParameter.parameterRoll_v.limitingMin = limitingMin;
}
