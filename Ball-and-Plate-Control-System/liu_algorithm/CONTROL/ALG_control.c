#include "ALG_control.h"
#include "Gen_include.h"
extern double vY;
extern int time;
/*************************总控制器*****************************/
void Main_Contriller(void)	
{
//	Mode_Contriller();				//模式检查
	Position_Controller();		//位置控制
}
extern int KEY_QUE;
extern int rad[4];
int po=0;
int pl=0;
/************************模式扫描******************************/
void Mode_Contriller(void)
{
	 
	switch(KEY_QUE)
	{
		case 1:   flag.positionX=Target_Position.twoCoreX;
							flag.positionY=Target_Position.twoCoreY;
							break;
		         
		case 2: 
			        if(po>=0&&po<=30)
							{
							flag.positionX=Target_Position.oneCoreX;
							flag.positionY=Target_Position.oneCoreY;
							po++;
		          }
							if(po>30&&po<=60)
							{
							flag.positionX=Target_Position.fiveCoreX;
							flag.positionY=Target_Position.fiveCoreY;
							po++;
							}
							if(po>60&&po<=90){po++;}
							if(po==91){po=-1;}
							break;
		case 3: 
			        if(po>=0&&po<=20)
							{
							flag.positionX=Target_Position.oneCoreX;
							flag.positionY=Target_Position.oneCoreY;	
							po++;
							}
							if(po>=20&&po<=40){po++;}
							if(po>40&&po<=60)
							{
							flag.positionX=Target_Position.fourCoreX;
							flag.positionY=Target_Position.fourCoreY;
							po++;
							}
     					if(po>60&&po<=80){po++;}
							if(po>80&&po<=100)
							{
							flag.positionX=Target_Position.fiveCoreX;
							flag.positionY=Target_Position.fiveCoreY;
							po++;
							}
							if(po==101) po=-1;
							break;
							
		case  4:  if(po>=0&&po<=30)
							{
							flag.positionX=Target_Position.oneCoreX;
							flag.positionY=Target_Position.oneCoreY;
							po++;
		          }
							if(po>30&&po<=60)
							{
							flag.positionX=Target_Position.nineCoreX;
							flag.positionY=Target_Position.nineCoreY;
							po++;
							}
							if(po>60&&po<=90){po++;}
							if(po==91){po=-1;}
							break;
							
		case  5:  if(po>=0&&po<=30)
							{
							flag.positionX=Target_Position.oneCoreX;
							flag.positionY=Target_Position.oneCoreY;	
							po++;
							}
							if(po>30&&po<=60)
							{
							flag.positionX=Target_Position.twoCoreX;
							flag.positionY=Target_Position.twoCoreY;
							po++;
							}
							if(po>60&&po<=90)
							{
							flag.positionX=Target_Position.sixCoreX;
							flag.positionY=Target_Position.sixCoreY;
							po++;
							}
							if(po>120&&po<=150)
							{
							flag.positionX=Target_Position.sixCoreX;
							flag.positionY=Target_Position.sixCoreY;
							po++;
							}
							if(po<=180&&po>=210)po++;
							if(po==211){po=-1;}
							break;  
		case  6:  
			      if(pl==1)
						{
		         if(po>=0&&po<=30)
							{
								thoose(0);
								po++;
							}
							if(po>30&&po<=60)
							{
								thoose(1);
								po++;
							}
	           if(po>60&&po<=90)
							{
								thoose(2);
								po++;
							}
              if(po>90&&po<=120)
							{
								thoose(3);
								po++;
							}			
							if(po==121)po=-1;
						}
						break;
	}
}
void rad_rad(void)
{

	static int j=0;
	if(j>=0&&j<=5)
	{
   flag.positionX=Target_Position.fiveCoreX+10;
	 flag.positionY=Target_Position.fiveCoreY;
	j++;
	}
	
	
  
      flag.positionX=Target_Position.fiveCoreX;
			flag.positionY=Target_Position.fiveCoreY;
}
void thoose(int i)
{
if(rad[i]==1)
{flag.positionX=Target_Position.oneCoreX;
flag.positionY=Target_Position.oneCoreY;}
if(rad[i]==2)
{flag.positionX=Target_Position.twoCoreX;
flag.positionY=Target_Position.twoCoreY;}
if(rad[i]==3)
{flag.positionX=Target_Position.threeCoreX;
flag.positionY=Target_Position.threeCoreY;}
if(rad[i]==4)
{flag.positionX=Target_Position.fourCoreX;
flag.positionY=Target_Position.fourCoreY;}
if(rad[i]==5)
{flag.positionX=Target_Position.fiveCoreX;
flag.positionY=Target_Position.fiveCoreY;}
if(rad[i]==6)
{flag.positionX=Target_Position.sixCoreX;
flag.positionY=Target_Position.sixCoreY;}
if(rad[i]==7)
{flag.positionX=Target_Position.sevenCoreX;
flag.positionY=Target_Position.sevenCoreY;}
if(rad[i]==8)
{flag.positionX=Target_Position.eightCoreX;
flag.positionY=Target_Position.eightCoreY;}
if(rad[i]==9)
{flag.positionX=Target_Position.nineCoreX;
flag.positionY=Target_Position.nineCoreY;}
}
/************************小球位置控制器***********************/
void Position_Controller(void)
{
  Control_pitch(Target_Position.fiveCoreY);
	Control_roll(Target_Position.fiveCoreX);
}
/***********************pitch 控制**************************/
void Control_pitch(double target)
{
	double output01=0,output02=0;
	output01 = pid_pitch_p(target);              //位置环(外环
	output02 = pit_pitct_v(output01);						 //速度环(内环
	Motor_pitch(output02);									
}
/***********************roll控制****************************/
void Control_roll(double target)
{
	double output01=0,output02=0;
	output01 = pid_roll_p(target);              //位置环(外环
	output02 = pit_roll_v(output01);						 //速度环(内环
	Motor_roll(output02);
}
/***********************舵机控制*****************************/
void Motor_pitch(double tarPitch)
{
	if(k.y>160)		TIM_SetCompare2(TIM3,(int)tarPitch+1370);
	if(k.y<60)		TIM_SetCompare2(TIM3,(int)tarPitch+1250);
	else				TIM_SetCompare2(TIM3,(int)tarPitch+1290);
	/*if(k.y<DPI/2)		TIM_SetCompare2(TIM3,(int)tarPitch+1270);
	if(k.y<DPI/2&&k.y<56)			TIM_SetCompare2(TIM3,(int)tarPitch+1240);	
	if(k.y<165&&k.y>DPI/2)		TIM_SetCompare2(TIM3,(int)tarPitch+1300);
	else					  TIM_SetCompare2(TIM3,(int)tarPitch+1310);*/
}
void Motor_roll(double tarRoll)
{
	if(k.x>160)	TIM_SetCompare1(TIM3,(int)tarRoll+1460);
	if(k.x<60)	TIM_SetCompare1(TIM3,(int)tarRoll+1470);
	else 				TIM_SetCompare1(TIM3,(int)tarRoll+1460);
/*	if(k.x>171)	TIM_SetCompare1(TIM3,(int)tarRoll+1410);
	if(k.x<DPI&&k.x>64)	TIM_SetCompare1(TIM3,(int)tarRoll+1430);
	if(k.x<171&&k.x>DPI)       	TIM_SetCompare1(TIM3,(int)tarRoll+1420);
  if(k.x<64)			TIM_SetCompare1(TIM3,(int)tarRoll+1440);
	else TIM_SetCompare1(TIM3,(int)tarRoll+1425);*/
}
void mode(int x)
{
if(x==2)	
{flag.positionX=Target_Position.twoCoreX;
		flag.positionY=Target_Position.twoCoreY;}
if(x==5)
{flag.positionX=Target_Position.fiveCoreX;
		flag.positionY=Target_Position.fiveCoreY;}
if(x==1)	
{flag.positionX=Target_Position.oneCoreX;
		flag.positionY=Target_Position.oneCoreY;}
if(x==3)	
{flag.positionX=Target_Position.threeCoreX;
		flag.positionY=Target_Position.threeCoreY;}
if(x==4)	
{flag.positionX=Target_Position.fourCoreX;
		flag.positionY=Target_Position.fourCoreY;}
if(x==6)	
{flag.positionX=Target_Position.sixCoreX;
		flag.positionY=Target_Position.sixCoreY;}
if(x==7)	
{flag.positionX=Target_Position.sevenCoreX;
		flag.positionY=Target_Position.sevenCoreY;}
if(x==8)	
{flag.positionX=Target_Position.eightCoreX;
		flag.positionY=Target_Position.eightCoreY;}
if(x==9)	
{flag.positionX=Target_Position.nineCoreX;
		flag.positionY=Target_Position.nineCoreY;}
}
void Control_five(void)
{
		 V0=0.89;
	   V1=-2.65;
	  Control_pitch(Target_Position.fiveCoreY);
	  Control_roll (Target_Position.fiveCoreY);
}