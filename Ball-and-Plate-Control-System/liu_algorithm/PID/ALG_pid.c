#include "ALG_pid.h"
#include "Gen_include.h"
extern double vY;
double V0=0;
double V1=0;
/*******************PID_pitch位置控制器*********************************/
double pid_pitch_p(double nextPoint)
{
	double error,error_1;
	double output=0;
	double kp,ki,kd;
	double i_error;
	double max_xianFu=9;
	double min_xianFu=-9;
	kp=AllPidParameter.parameterPitch_p.k_p;
	ki=AllPidParameter.parameterPitch_p.k_i;
	kd=AllPidParameter.parameterPitch_p.k_d;
	
	error=(nextPoint-k.y);
  AllPidParameter.parameterPitch_p.error=error;
	output=kp*error+ki*i_error+kd*(error-error_1);	
	
	AllPidParameter.parameterPitch_p.output01=output;
	output = (output>max_xianFu)?max_xianFu:output;
	output = (output<min_xianFu)?min_xianFu:output;
	AllPidParameter.parameterPitch_p.output02=output;
	
	i_error =(error<15)? i_error+error:i_error;
	i_error =(i_error>25)? 25:i_error;
	i_error =(i_error<-25)? -25:i_error;
	

	error_1=error;
	return output;
}
/*******************PID_pitch速度控制器*********************************/
double pit_pitct_v(double output_wai)
{
	double error,error_1;
	double output=0;
	double kp,kd;
	double max_xianFu=(160);
	double min_xianfu=(-160);

  if(k.y>98)		
	{
		output_wai+=(-0.67);//-1.4
	}
	if(k.y<98)
	{
			output_wai-=(0);
	}
	kp=AllPidParameter.parameterPitch_v.k_p;
	kd=AllPidParameter.parameterPitch_v.k_d;

	error=-(output_wai-vY);
  AllPidParameter.parameterPitch_v.error=error;
	output=kp*error+kd*(error-error_1);	

	AllPidParameter.parameterPitch_v.output01=output;
	output = (output>max_xianFu)?max_xianFu:output;
	output = (output<min_xianfu)?min_xianfu:output;
	AllPidParameter.parameterPitch_v.output02=output;
	error_1=error;
	return output;
}
/*******************PID_roll位置控制器*********************************/
double pid_roll_p(double nextPoint)
{
	double error,error_1;
	double output=0;
	double kp,ki,kd;
	double i_error;
	double max_xianFu=9;
	double min_xianFu=-9;
	kp=AllPidParameter.parameterRoll_p.k_p;
	ki=AllPidParameter.parameterRoll_p.k_i;
	kd=AllPidParameter.parameterRoll_p.k_d;
	
	error=(nextPoint-k.x);
  AllPidParameter.parameterPitch_p.error=error;
	output=kp*error+ki*i_error+kd*(error-error_1);	
	
	i_error =(error<15)? i_error+error:i_error;
	i_error =(i_error>35||error<-35)? 0:i_error;
	
	AllPidParameter.parameterRoll_p.output01=output;
	output = (output>max_xianFu)?max_xianFu:output;
	output = (output<min_xianFu)?min_xianFu:output;
	AllPidParameter.parameterRoll_p.output02=output;
	error_1=error;
	return output;
}
/*******************PID_roll速度控制器*********************************/
double pit_roll_v(double output_wai)
{
	double error,error_1;
	double output=0;
	double kp,kd;
	double max_xianFu=(160);
	double min_xianfu=(-160);

	if(k.x>102)				output_wai+=(0);//-5.23
	else 							output_wai-=(-0);//-4.23

	kp=AllPidParameter.parameterPitch_v.k_p;
	kd=AllPidParameter.parameterPitch_v.k_d;
	
	error=(output_wai-vX);
  AllPidParameter.parameterRoll_v.error=error;
	output=kp*error+kd*(error-error_1);	
	
	AllPidParameter.parameterRoll_v.output01=output;
	output = (output>max_xianFu)?max_xianFu:output;
	output = (output<min_xianfu)?min_xianfu:output;
	AllPidParameter.parameterRoll_v.output02=output;
	error_1=error;
	return output;
}




