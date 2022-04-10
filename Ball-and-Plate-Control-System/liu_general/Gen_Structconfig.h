#ifndef __STRUCT_H
#define __STRUCT_H

typedef struct
{
	u8 start_ok;
	u8 run;
	char mode;
	int positionX;
	int positionY;
}_flag;

typedef struct
{
	double pitch;
	double roll;
	double roll_pre;
	double yaw;
	double pitchV;
	double rollV;
}_attitude;

typedef struct
{
	u16 y;
	u16 x;
}_basePoint;

typedef struct
{
	u16 yMax;
	u16 yMin;
	u16 xMax;
	u16 xMin;
	u16 y;
	u16 x;
	u16 ball_y;
	u16 ball_x;

}_ballPoint;
	
typedef struct
{
	double k_p;
	double k_i;
	double k_d;
	double error;
	double error_1;
	double error_2;
	double limitingMax;
	double limitingMin;
	double output01;
	double output02;
}_PidParameter;
typedef struct
{
	_PidParameter parameterPitch_p;
	_PidParameter parameterPitch_v;
	_PidParameter parameterRoll_p;
	_PidParameter	parameterRoll_v;
}_AllPidParameter;

typedef struct
{
	int oneCoreX;
	int oneCoreY;
	int twoCoreX;
	int twoCoreY;
	int threeCoreX;	
	int threeCoreY;	
	int fourCoreX;	
	int fourCoreY;
	int fiveCoreX;	
	int fiveCoreY;
	int sixCoreX;
	int sixCoreY;
	int sevenCoreX;	
	int sevenCoreY;
	int eightCoreX;	
	int eightCoreY;
	int nineCoreX;	
	int nineCoreY;
}_Target_Position; 
#endif
