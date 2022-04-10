#include "sys.h"
#include "usart3_it.h"
#include "usart3.h"
/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/
extern uint8_t stata_reg;//����״̬�Ĵ���
extern uint8_t data1_buf[7],data2_buf[7],data3_buf[7],
data4_buf[7],data5_buf[9];
//////////////
/*����ACC��GYR�Ȳ�ͬ�����ݶ�Ӧ���գ����ں��ڼӹ�ʹ��*/
///////////
void USART3_IRQHandler(void)   
{
	static uint8_t rebuf[13]={0},i=0;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		rebuf[i++]=USART_ReceiveData(USART3);
		if(rebuf[0]!=0x5a)//�ж�֡ͷ
			i=0;
	  if((i==2)&&(rebuf[1]!=0x5a))//�ж�֡ͷ
			i=0;
		if(i>4)//��i����ֵ=5ʱ�������ֽڽ�����ϣ����ݳ����ֽڽ������
		{
			switch(rebuf[2])//�жϹ����ֽ�
			{
				case 0x15:data1_buf[i-5]=rebuf[i-1];break;//������ٶ�����
				case 0x25:data2_buf[i-5]=rebuf[i-1];break;//��������������
				case 0x35:data3_buf[i-5]=rebuf[i-1];break;//����ų�����
				case 0x45:data4_buf[i-5]=rebuf[i-1];break;//����ŷ��������
				case 0x65:data5_buf[i-5]=rebuf[i-1];break;//������Ԫ������
			}

			//�ж����ݽ������
			//rebuf[3]Ϊ���ݸ�����5=��֡ͷ+1�������ֽ�+1�����ݳ����ֽ�+1������У����ֽ�
			if(i==rebuf[3]+5)
			{
					switch(rebuf[2])
				{
					case 0x15:stata_reg|=ACC;break;//���ٶ����ݽ������
					case 0x25:stata_reg|=GYR;break;//���������ݽ������
					case 0x35:stata_reg|=MAG;break;//�ų����ݽ������
					case 0x45:stata_reg|=RPY;break;//ŷ�������ݽ������
					case 0x65:stata_reg|=Q4;break;//��Ԫ�����ݽ������
				}
				i=0;
			}
    }
	USART_ClearFlag(USART3,USART_FLAG_RXNE);//���жϱ�־
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
