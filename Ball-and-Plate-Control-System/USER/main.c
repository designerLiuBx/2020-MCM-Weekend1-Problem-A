#include "Gen_include.h"
#include "sys.h"
extern K k;

int main(void)
{
	flag.start_ok = All_Init();		//���������豸�ĳ�ʼ����������ʼ���������
	dev_SysTick_init();
	TIM_SetCompare1(TIM3,1460);
	TIM_SetCompare2(TIM3,1290);//1290
	delay_ms(200);
	printf_s("ok");
	delay_ms(5);
  while(1)
	{		 	
		if(flag.start_ok==1)
				Scheduler_Run();
	}
}

