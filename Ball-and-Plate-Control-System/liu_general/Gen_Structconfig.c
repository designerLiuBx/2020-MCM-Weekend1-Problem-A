#include "Gen_include.h"
#include "Gen_Structconfig.h"

_flag flag;
_attitude attitude;

_basePoint basePoint;
_ballPoint ballPoint;
_Target_Position Target_Position;

_AllPidParameter AllPidParameter;

int Pwm1,Pwm2;
double angleTestp,angleTestr;
double kpTest,tiTest,tdTest,limitingMaxTest,limitingMinTest;

int pwmPitch;
int pwmRoll;

	uint8_t  data_buf[9]={0};
	int16_t  ROLL=0,PITCH=0,YAW=0;
	int16_t  rpy[3]={0},Acc[3]={0},Gyr[3]={0},Mag[3]={0},Q[4]={0};
