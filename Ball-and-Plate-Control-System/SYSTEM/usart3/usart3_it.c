#include "sys.h"
#include "usart3_it.h"
#include "usart3.h"
/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/
extern uint8_t stata_reg;//接收状态寄存器
extern uint8_t data1_buf[7],data2_buf[7],data3_buf[7],
data4_buf[7],data5_buf[9];
//////////////
/*更据ACC、GYR等不同种数据对应接收，便于后期加工使用*/
///////////
void USART3_IRQHandler(void)   
{
	static uint8_t rebuf[13]={0},i=0;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		rebuf[i++]=USART_ReceiveData(USART3);
		if(rebuf[0]!=0x5a)//判断帧头
			i=0;
	  if((i==2)&&(rebuf[1]!=0x5a))//判断帧头
			i=0;
		if(i>4)//当i计数值=5时，功能字节接受完毕，数据长度字节接收完毕
		{
			switch(rebuf[2])//判断功能字节
			{
				case 0x15:data1_buf[i-5]=rebuf[i-1];break;//保存加速度数据
				case 0x25:data2_buf[i-5]=rebuf[i-1];break;//保存陀螺仪数据
				case 0x35:data3_buf[i-5]=rebuf[i-1];break;//保存磁场数据
				case 0x45:data4_buf[i-5]=rebuf[i-1];break;//保存欧拉角数据
				case 0x65:data5_buf[i-5]=rebuf[i-1];break;//保存四元数数据
			}

			//判断数据接收完毕
			//rebuf[3]为数据个数，5=两帧头+1个功能字节+1个数据长度字节+1个数据校验和字节
			if(i==rebuf[3]+5)
			{
					switch(rebuf[2])
				{
					case 0x15:stata_reg|=ACC;break;//加速度数据接收完毕
					case 0x25:stata_reg|=GYR;break;//陀螺仪数据接收完毕
					case 0x35:stata_reg|=MAG;break;//磁场数据接收完毕
					case 0x45:stata_reg|=RPY;break;//欧拉角数据接收完毕
					case 0x65:stata_reg|=Q4;break;//四元数数据接收完毕
				}
				i=0;
			}
    }
	USART_ClearFlag(USART3,USART_FLAG_RXNE);//清中断标志
	}	
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
