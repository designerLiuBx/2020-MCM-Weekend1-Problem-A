#ifndef __INIT_H
#define __INIT_H	 
#include "sys.h"
#include "Gen_include.h"
u8 All_Init(void);

void Set_angle(double angleTestp1, double angleTestr1);
void Set_pidParv_pitch_p(double kp, double ti, double td , double limitingMax, double limitingMin);
void Set_pidPar_pitch_v(double kp, double ti, double td , double limitingMax, double limitingMin);
void Set_pidPar_roll_p(double kp, double ti, double td , double limitingMax, double limitingMin);
void Set_pidPar_roll_v(double kp, double ti, double td , double limitingMax, double limitingMin);

#endif

