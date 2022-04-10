#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "sys.h"
#include "Gen_include.h"
void Main_Contriller(void);
void Position_Controller(void);
void Control_roll(double target);
void Control_pitch(double target);
void Motor_pitch(double tarPitch);
void Motor_roll(double tarRoll);
void thoose(int i);
void Mode_Contriller(void);void Angle_Controller(void);
void mode(int x);
void rad_rad(void);
void Set_angle(double angleTestp1, double angleTestr1);
void	Control_five(void);

#endif

