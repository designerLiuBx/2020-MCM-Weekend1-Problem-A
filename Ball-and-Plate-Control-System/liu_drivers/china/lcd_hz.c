#include "sys.h"
#include "lcd_hz.h"
#include "lcd.h"
#include "w25qxx.h"
#include "key.h"
#include "delay.h"
/**********************************/
int p=0;
static int z=0;
static int a=0;
int KEY_QUE;
int rad[4]={0};
extern int po;
extern int pl;
/************************************/
void disp_show(void)
{
static int stat=0,q=0,t=0;
key_scan(0);
	 if(q==0)
	{
		 KEY_QUE=0;
	  	po=0;
		  pl=0;
			if(t!=0)
			{
				t=0;
				p=0;
				LCD_Clear(BLACK);
			}
			if(keydown_data==KEY1_DATA)
			{
				if(stat<8)stat++;
				else stat=0;
			}
			 if(keydown_data==KEY0_DATA)
			{
			if(stat>0)stat--;
			if(stat==0)stat=8;
			}
			if(keydown_data==KEY2_DATA)
			{
				q=1;
				p=stat;
			}
			show_0(10,10);
			if(stat==1)BRUSH_COLOR=BLUE;
			show_1(10,22);
			if(stat==2)BRUSH_COLOR=BLUE;
			show_2(10,46);
			if(stat==3)BRUSH_COLOR=BLUE;
			show_3(10,70);
			if(stat==4)BRUSH_COLOR=BLUE;
			show_4(10,118);
			show_5_0(10,142);
			if(stat==5)BRUSH_COLOR=BLUE;
			show_5_1(10,154);
			if(stat==6)BRUSH_COLOR=BLUE;
			show_5_2(10,190);
			if(stat==7)BRUSH_COLOR=BLUE;
			show_5_3(10,226);
		
  }
	else if(q==1)
	{
		 KEY_QUE=p;
	   if(p==1&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
		 }
		else if(t==1&&p==1)
		 {
			 if(keydown_data==KEY3_DATA)q=0;
			 rad_b_1();
		 }
		 if(p==2&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
		 }
		 else if(t==1&&p==2)
		 {
			 if(keydown_data==KEY3_DATA)q=0;
			 rad_b_2();
		 }
		  if(p==3&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
		 }
		 else if(t==1&&p==3)
		 {
			 if(keydown_data==KEY3_DATA)q=0;
			 rad_b_3();
		 }
	   if(p==4&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
		 }
		 else if(t==1&&p==4)
		 {
			 if(keydown_data==KEY3_DATA)q=0;
			 rad_b_4();
		 }
	   	 if(p==5&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
		 }
		 else if(t==1&&p==5)
		 {
			 if(keydown_data==KEY3_DATA)q=0;
			 rad_k_1();
		 }
		 if(p==6&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
	    a=0;
		 }
		 else if(t==1&&p==6)
		 {
			  if(keydown_data==KEY3_DATA)
				{
					q=0;
				}
			  rad_k_2();
				
		 }
		 if(p==7&&t==0)
		 {
		  LCD_Clear(BLACK);
			t=1;
	    a=0;
		 }
		 else if(t==1&&p==7)
		 {
			  if(z==0)
			  if(keydown_data==KEY3_DATA)q=0;
			  rad_k_3();
		 }
	}
	


}
void rad_b_1(void)
{
 
	if(z==0)
	{
	LCD_Clear(BLACK);
		z=1;
	}
  rad_1(BLUE);
	rad_2(RED);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(BLUE);
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	show_1(15,230);
}
void rad_b_2(void)
{
	if(z==0)
	{
	LCD_Clear(BLACK);
		z=1;
	}
  rad_1(RED);
	rad_2(BLUE);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(RED);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(40,40,120,120);
	LCD_Draw_Line(100,120,120,120);
	LCD_Draw_Line(120,100,120,120);
	BRUSH_COLOR=WHITE;
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	show_2(15,230);
}
void rad_b_3(void)
{
	static int i=0;
	if(i<=20&&i>=0)
	{
  rad_1(RED);
	rad_2(BLUE);
	rad_3(BLUE);
	rad_4(RED);
	rad_5(BLUE);
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(40,40,40,120);
	LCD_Draw_Line(20,100,40,120);
	LCD_Draw_Line(60,100,40,120);
	BRUSH_COLOR=WHITE;
	show_3(15,230);
	i++;
	}
	else if(i>20&&i<=40)
	{
		if(i==21)
		{
	LCD_Clear(BLACK);
		}
	rad_1(BLUE);
	rad_2(BLUE);
	rad_3(BLUE);
	rad_4(RED);
	rad_5(RED);
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(40,120,120,120);
	LCD_Draw_Line(100,100,120,120);
	LCD_Draw_Line(100,140,120,120);
	BRUSH_COLOR=WHITE;
	show_3(15,230);
		i++;
	}
	else if(i>40)
	{
	LCD_Clear(BLACK);
	i=0;
	}

}

void rad_b_4(void)
{

	static int i=0;
	if(i<=10&&i>=0)
	{
  rad_1(RED);
	rad_2(BLUE);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(BLUE);
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(RED);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(40,40,200,200);
	LCD_Draw_Line(180,200,200,200);
	LCD_Draw_Line(200,180,200,200);
	BRUSH_COLOR=WHITE;
	show_4(15,230);
	i++;
	}
  if(i>10&&i<=15)
 {	
	 if(i==11)
	 {
	LCD_Clear(BLACK);
	 }
	rad_1(BLUE);
	rad_2(BLUE);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(BLUE);
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	show_4(15,230);
  i++;
 }
 	else if(i>15)
	{
	LCD_Clear(BLACK);
	i=0;
	show_4(15,230);
	}
}
void rad_k_1(void)
{
	static int i=0;
	if(i<=20&&i>=0)
	{
  rad_1(RED);
	rad_2(RED);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(BLUE);
	rad_6(BLUE);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(40,40,120,40);
	LCD_Draw_Line(100,30,120,40);
	LCD_Draw_Line(100,50,120,40);
	BRUSH_COLOR=WHITE;
	show_5_1(15,230);
	i++;
	}
  if(i>20&&i<=40)
	{
		if(i==21)
		{
	  LCD_Clear(BLACK);
		}
  rad_1(BLUE);
	rad_2(RED);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(BLUE);
	rad_6(RED);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(BLUE);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(120,40,200,120);
	LCD_Draw_Line(180,120,200,120);
	LCD_Draw_Line(200,100,200,120);
	BRUSH_COLOR=WHITE;
	show_5_1(15,230);
	i++;
	}
	if(i>40&&i<=60)
	{
		if(i==41)
		{
	LCD_Clear(BLACK);
		}
	rad_1(BLUE);
	rad_2(BLUE);
	rad_3(BLUE);
	rad_4(BLUE);
	rad_5(BLUE);
	rad_6(RED);
	rad_7(BLUE);
  rad_8(BLUE);
	rad_9(RED);
	BRUSH_COLOR=YELLOW;
	LCD_Draw_Line(200,120,200,200);
	LCD_Draw_Line(180,180,200,200);
	LCD_Draw_Line(220,180,200,200);
	BRUSH_COLOR=WHITE;
	show_5_1(15,230);
	i++;
	}
	if(i>60)
	{
	LCD_Clear(BLACK);
		i=0;
	}
}

int rad_k_2_1(void)
{
	static int stat=0;
	static int i=0;
	static int o=0;
	key_scan(0);
	if(keydown_data==KEY1_DATA) stat+=1;
	if(keydown_data==KEY0_DATA)	if(stat>0)stat-=1;
	if(keydown_data==KEY2_DATA)	
	{
	rad[i]=stat;
	i++;	
	if(i==4)
	{
		o=1;
		pl=1;
	}
	}
	if(keydown_data==KEY3_DATA)	
	{
	i--;
	rad[i]=0;
	}
	if(stat!=1)rad_1(BLUE);
	if(stat!=2)rad_2(BLUE);
	if(stat!=3)rad_3(BLUE);
	if(stat!=4)rad_4(BLUE);
	if(stat!=5)rad_5(BLUE);
	if(stat!=6)rad_6(BLUE);
	if(stat!=7)rad_7(BLUE);
  if(stat!=8)rad_8(BLUE);
	if(stat!=9)rad_9(BLUE);
	if(stat==10)  stat=0;
	if(stat==1) 	rad_1(RED);
	if(stat==2) 	rad_2(RED);
	if(stat==3) 	rad_3(RED);
	if(stat==4) 	rad_4(RED);
	if(stat==5) 	rad_5(RED);
	if(stat==6) 	rad_6(RED);
	if(stat==7) 	rad_7(RED);
	if(stat==8) 	rad_8(RED);
	if(stat==9) 	rad_9(RED);
	show_5_2(15,230);
	LCD_DisplayChar(15,270,'A',12);
	LCD_DisplayChar(27,270,'=',12);
	LCD_DisplayNum(39,270,rad[0],1,12,1);
	LCD_DisplayChar(91,270,'B',12);
	LCD_DisplayChar(103,270,'=',12);
	LCD_DisplayNum(114,270,rad[1],1,12,1);
	LCD_DisplayChar(181,270,'C',12);
	LCD_DisplayChar(193,270,'=',12);
	LCD_DisplayNum(205,270,rad[2],1,12,1);
	LCD_DisplayChar(91,292,'D',12);
	LCD_DisplayChar(103,292,'=',12);
	LCD_DisplayNum(114,292,rad[3],1,12,1);
	if(o==1)
	{
		o=0;
		return 1;
	}
	return 0;
}

void rad_k_2(void)
{
	
	static int x[4],y[4];
  static int z=0,k=0,h=0;
	if(a==0)
	{
    a=rad_k_2_1();
		if(z==0)
		{
     LCD_Clear(BLACK);
		}
	  z=1;
  } 
	if(a==1)
	{
  for(int i=0,k;i<=3;i++)
	{
	  k=rad[i];
		if(k==1) 
		{
		x[i]=40;
		y[i]=40;
		}
		if(k==2) 
		{
		x[i]=120;
		y[i]=40;
		}
		if(k==3) 
		{
		x[i]=200;
		y[i]=40;
		}
		if(k==4) 
		{
		x[i]=40;
		y[i]=120;
		}
		if(k==5) 
		{
		x[i]=120;
		y[i]=120;
		}
		if(k==6) 
		{
		x[i]=200;
		y[i]=120;
		}
		if(k==7) 
		{
		x[i]=40;
		y[i]=200;
		}	
	  if(k==8) 
		{
		x[i]=120;
		y[i]=200;
		}
  	 if(k==9) 
		{
		x[i]=200;
		y[i]=200;
		}
		a=2;
   }
  }
  if(a==2)
	{
		if(h>=0&&h<=5)
		{
		if(rad[0]!=1&&rad[1]!=1)rad_1(BLUE);
		if(rad[0]!=2&&rad[1]!=2)rad_2(BLUE);
		if(rad[0]!=3&&rad[1]!=3)rad_3(BLUE);
		if(rad[0]!=4&&rad[1]!=4)rad_4(BLUE);
		if(rad[0]!=5&&rad[1]!=5)rad_5(BLUE);
		if(rad[0]!=6&&rad[1]!=6)rad_6(BLUE);
		if(rad[0]!=7&&rad[1]!=7)rad_7(BLUE);
		if(rad[0]!=8&&rad[1]!=8)rad_8(BLUE);
		if(rad[0]!=9&&rad[1]!=9)rad_9(BLUE);
		h++;
		}
	if(h>5&&h<=10)	{h++;}
  if(h==11)
	{
			show_5_2(15,230);
  for(int i=0;i<=1;i++)
	{
 	if(rad[i]==1) 	rad_1(RED);
	if(rad[i]==2) 	rad_2(RED);
	if(rad[i]==3) 	rad_3(RED);
	if(rad[i]==4) 	rad_4(RED);
	if(rad[i]==5) 	rad_5(RED);
	if(rad[i]==6) 	rad_6(RED);
	if(rad[i]==7) 	rad_7(RED);
	if(rad[i]==8) 	rad_8(RED);
	if(rad[i]==9) 	rad_9(RED);
	}
	 h++;
  }
	if(h>11&&h<=15)
	{
	show_5_2(15,230);
	LCD_DisplayChar(15,270,'A',12);
	LCD_DisplayChar(27,270,'=',12);
	LCD_DisplayNum(39,270,rad[0],1,12,1);
	LCD_DisplayChar(91,270,'B',12);
	LCD_DisplayChar(103,270,'=',12);
	LCD_DisplayNum(114,270,rad[1],1,12,1);
	LCD_DisplayChar(181,270,'C',12);
	LCD_DisplayChar(193,270,'=',12);
	LCD_DisplayNum(205,270,rad[2],1,12,1);
	LCD_DisplayChar(91,292,'D',12);
	LCD_DisplayChar(103,292,'=',12);
	LCD_DisplayNum(114,292,rad[3],1,12,1);
	LCD_Draw_Line(x[0],y[0],x[1],y[1]);
	h++;
	}
  if(h>15&&h<=20)h++;
	if(h>20&&h<=25)
	{
	if(h==21)LCD_Clear(BLACK);
	show_5_2(15,230);
	LCD_DisplayChar(15,270,'A',12);
	LCD_DisplayChar(27,270,'=',12);
	LCD_DisplayNum(39,270,rad[0],1,12,1);
	LCD_DisplayChar(91,270,'B',12);
	LCD_DisplayChar(103,270,'=',12);
	LCD_DisplayNum(114,270,rad[1],1,12,1);
	LCD_DisplayChar(181,270,'C',12);
	LCD_DisplayChar(193,270,'=',12);
	LCD_DisplayNum(205,270,rad[2],1,12,1);
	LCD_DisplayChar(91,292,'D',12);
	LCD_DisplayChar(103,292,'=',12);
	LCD_DisplayNum(114,292,rad[3],1,12,1);
	if(rad[2]!=1&&rad[1]!=1)rad_1(BLUE);
	if(rad[2]!=2&&rad[1]!=2)rad_2(BLUE);
	if(rad[2]!=3&&rad[1]!=3)rad_3(BLUE);
	if(rad[2]!=4&&rad[1]!=4)rad_4(BLUE);
	if(rad[2]!=5&&rad[1]!=5)rad_5(BLUE);
	if(rad[2]!=6&&rad[1]!=6)rad_6(BLUE);
	if(rad[2]!=7&&rad[1]!=7)rad_7(BLUE);
	if(rad[2]!=8&&rad[1]!=8)rad_8(BLUE);
	if(rad[2]!=9&&rad[1]!=9)rad_9(BLUE);
	h++;
	}
	if(h>25&&h<=30){h++;	show_5_2(15,230);}
	if(h==31)
	{
		for(int i=1;i<=2;i++)
		{
		if(rad[i]==1) 	rad_1(RED);
		if(rad[i]==2) 	rad_2(RED);
		if(rad[i]==3) 	rad_3(RED);
		if(rad[i]==4) 	rad_4(RED);
		if(rad[i]==5) 	rad_5(RED);
		if(rad[i]==6) 	rad_6(RED);
		if(rad[i]==7) 	rad_7(RED);
		if(rad[i]==8) 	rad_8(RED);
		if(rad[i]==9) 	rad_9(RED);
		}
		h++;
  }
	if(h>31&&h<=35)
	{
		show_5_2(15,230);
		LCD_DisplayChar(15,270,'A',12);
		LCD_DisplayChar(27,270,'=',12);
		LCD_DisplayNum(39,270,rad[0],1,12,1);
		LCD_DisplayChar(91,270,'B',12);
		LCD_DisplayChar(103,270,'=',12);
		LCD_DisplayNum(114,270,rad[1],1,12,1);
		LCD_DisplayChar(181,270,'C',12);
		LCD_DisplayChar(193,270,'=',12);
		LCD_DisplayNum(205,270,rad[2],1,12,1);
		LCD_DisplayChar(91,292,'D',12);
		LCD_DisplayChar(103,292,'=',12);
		LCD_DisplayNum(114,292,rad[3],1,12,1);
		LCD_Draw_Line(x[1],y[1],x[2],y[2]);
		h++;
	 }
  if(h>35&&h<=40)
	{
	if(h==71)	LCD_Clear(BLACK);
	show_5_2(15,230);
	LCD_DisplayChar(15,270,'A',12);
	LCD_DisplayChar(27,270,'=',12);
	LCD_DisplayNum(39,270,rad[0],1,12,1);
	LCD_DisplayChar(91,270,'B',12);
	LCD_DisplayChar(103,270,'=',12);
	LCD_DisplayNum(114,270,rad[1],1,12,1);
	LCD_DisplayChar(181,270,'C',12);
	LCD_DisplayChar(193,270,'=',12);
	LCD_DisplayNum(205,270,rad[2],1,12,1);
	LCD_DisplayChar(91,292,'D',12);
	LCD_DisplayChar(103,292,'=',12);
	LCD_DisplayNum(114,292,rad[3],1,12,1);
	if(rad[2]!=1&&rad[3]!=1)rad_1(BLUE);
	if(rad[2]!=2&&rad[3]!=2)rad_2(BLUE);
	if(rad[2]!=3&&rad[3]!=3)rad_3(BLUE);
	if(rad[2]!=4&&rad[3]!=4)rad_4(BLUE);
	if(rad[2]!=5&&rad[3]!=5)rad_5(BLUE);
	if(rad[2]!=6&&rad[3]!=6)rad_6(BLUE);
	if(rad[2]!=7&&rad[3]!=7)rad_7(BLUE);
	if(rad[2]!=8&&rad[3]!=8)rad_8(BLUE);
	if(rad[2]!=9&&rad[3]!=9)rad_9(BLUE);
	h++;
	}
	if(h==41)
	{
		for(int i=2;i<=3;i++)
		{
		if(rad[i]==1) 	rad_1(RED);
		if(rad[i]==2) 	rad_2(RED);
		if(rad[i]==3) 	rad_3(RED);
		if(rad[i]==4) 	rad_4(RED);
		if(rad[i]==5) 	rad_5(RED);
		if(rad[i]==6) 	rad_6(RED);
		if(rad[i]==7) 	rad_7(RED);
		if(rad[i]==8) 	rad_8(RED);
		if(rad[i]==9) 	rad_9(RED);
		}
		h++;
  }
	if(h>41&&h<=45)
	{
	show_5_2(15,230);
	LCD_DisplayChar(15,270,'A',12);
	LCD_DisplayChar(27,270,'=',12);
	LCD_DisplayNum(39,270,rad[0],1,12,1);
	LCD_DisplayChar(91,270,'B',12);
	LCD_DisplayChar(103,270,'=',12);
	LCD_DisplayNum(114,270,rad[1],1,12,1);
	LCD_DisplayChar(181,270,'C',12);
	LCD_DisplayChar(193,270,'=',12);
	LCD_DisplayNum(205,270,rad[2],1,12,1);
	LCD_DisplayChar(91,292,'D',12);
	LCD_DisplayChar(103,292,'=',12);
	LCD_DisplayNum(114,292,rad[3],1,12,1);
	LCD_Draw_Line(x[2],y[2],x[3],y[3]);
	h++;
	}
  if(h==46)
	{
	LCD_Clear(BLACK);
	h=0;
	}
 }
}

void putchar_hz(u16 x,u16 y, int set)
{
            //数据所在的位置
	u8 byte_data;
	u16 ymid=y;
	u8 byte[24];
	  W25QXX_Read((u8*)byte,set*24,24);
    for(int b=0;b<=24;b++)    
	  {
			byte_data=byte[b];
	    	for(int a=0;a<8;a++)
				{			    
						if(byte_data&0x80)LCD_Color_DrawPoint(x,y,BRUSH_COLOR);
						else LCD_Color_DrawPoint(x,y,BACK_COLOR);
						byte_data<<=1;
						y++;
						if(y>=lcd_height)return;		//超区域，退出函数
						if((y-ymid)==12)
						{
							y=ymid;
							x++;
							if(x>=lcd_width)return;	  //超区域，退出函数
							break;
						}
	       }
	
	  }

}

void show_0(int x,int y)
{
  int a=x,b=y;
	for(int i=154;i<159;i++)
	{
	 putchar_hz(a,b,i);
		if(a>=210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}
void show_1(int x,int y)
{
  int a=x,b=y;
	LCD_DisplayChar(a,b,'1',12);
	a+=10;
	for(int i=0;i<25;i++)
	{
	 putchar_hz(a,b,i);
		if(a>=210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}

void show_2(int x,int y)
{
int a=x,b=y;
	LCD_DisplayChar(a,b,'2',12);
	a+=10;
	for(int i=25;i<56;i++)
	{
		
	 putchar_hz(a,b,i);
		if(a>=210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}

void show_3(int x,int y)
{

  int a=x,b=y;
	LCD_DisplayChar(a,b,'3',12);
	a+=10;
	for(int i=56;i<122;i++)
	{
		
	 putchar_hz(a,b,i);
		if(a>=210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}
void show_4(int x,int y)
{

  int a=x,b=y;
	LCD_DisplayChar(a,b,'4',12);
	a+=10;
	for(int i=122;i<154;i++)
	{
		
	 putchar_hz(a,b,i);
		if(a>210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}
void show_5_0(int x,int y)
{
  int a=x,b=y;
	for(int i=159;i<164;i++)
	{
		
	 putchar_hz(a,b,i);
		if(a>210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}
void show_5_1(int x,int y)
{
  int a=x,b=y;
	LCD_DisplayChar(a,b,'1',12);
	a+=10;
	for(int i=164;i<210;i++)
	{
		
	 putchar_hz(a,b,i);
		if(a>210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}
void show_5_2(int x,int y)
{
  int a=x,b=y;
	LCD_DisplayChar(a,b,'2',12);
	a+=10;
	for(int i=210;i<250;i++)
	{
	 putchar_hz(a,b,i);
		if(a>210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}

void show_5_3(int x,int y)
{
  int a=x,b=y;
	LCD_DisplayChar(a,b,'3',12);
	a+=10;
	for(int i=250;i<297;i++)
	{
	 putchar_hz(a,b,i);
		if(a>210) 
		{
			a=x;
			b+=12;
		}
		else a+=12;
	}
	BRUSH_COLOR=WHITE;
}
void rad_1(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(40,40,i);
}
BRUSH_COLOR=WHITE;
}
void rad_2(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(120,40,i);
}
BRUSH_COLOR=WHITE;
}

void rad_3(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(200,40,i);
}
BRUSH_COLOR=WHITE;
}

void rad_4(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(40,120,i);
}
BRUSH_COLOR=WHITE;
}

void rad_5(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(120,120,i);
}
BRUSH_COLOR=WHITE;
}
void rad_6(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(200,120,i);
}
BRUSH_COLOR=WHITE;
}
void rad_7(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(40,200,i);
}
BRUSH_COLOR=WHITE;
}
void rad_8(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(120,200,i);
}
BRUSH_COLOR=WHITE;
}
void rad_9(u16 x)
{
BRUSH_COLOR=x;
for(int i=0;i<=12;i++)
{
LCD_Draw_Circle(200,200,i);
}
BRUSH_COLOR=WHITE;
}

void rad_k_3(void)
{
	show_5_3(15,230);
}
/*
void pow_rad(u16 x0,u16 y0,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0+a,y0-b);             
 		LCD_DrawPoint(x0+b,y0-a);                    
		LCD_DrawPoint(x0+b,y0+a);                       
		LCD_DrawPoint(x0+a,y0+b);             
		LCD_DrawPoint(x0-a,y0+b);             
 		LCD_DrawPoint(x0-b,y0+a);             
		LCD_DrawPoint(x0-a,y0-b);                      
  	LCD_DrawPoint(x0-b,y0-a);               	         
		a++;	
		if(di<0)di +=4*a+6;	  //使用Bresenham算法画圆     
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} */
