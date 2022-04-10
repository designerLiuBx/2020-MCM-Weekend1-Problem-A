#ifndef __LCD_HZ_H
#define __LCD_HZ_H
#include "sys.h"
void putchar_hz(u16 x,u16 y,int set);
void disp_show(void);
void show_0(int x,int y);
void show_1(int x,int y);
void show_2(int x,int y);
void show_3(int x,int y);
void show_4(int x,int y);
void show_5_0(int x,int y);
void show_5_1(int x,int y);
void show_5_2(int x,int y);
void show_5_3(int x,int y);
void rad_1(u16 x);
void rad_2(u16 x);
void rad_3(u16 x);
void rad_4(u16 x);
void rad_5(u16 x);
void rad_6(u16 x);
void rad_7(u16 x);
void rad_8(u16 x);
void rad_9(u16 x);
void rad_b_1(void);
void rad_b_2(void);
void rad_b_3(void);
void rad_b_4(void);
void rad_k_1(void);
void rad_k_2(void);
int rad_k_2_1(void);
void rad_k_3(void);
/*****************************
#define WHITE        0xFFFF
#define BLACK        0x0000	  
#define BLUE         0x001F 
#define GREEN        0x07E0
#define BRED         0XF81F
#define GRED 			   0XFFE0
#define GBLUE			   0X07FF
#define BROWN 			 0XBC40  
#define BRRED 			 0XFC07  
#define GRAY  			 0X8430  
#define RED          0xF800
#define MAGENTA      0xF81F
#define CYAN         0x7FFF
#define YELLOW       0xFFE0
****************************/
#endif

