#ifndef __SPI_H
#define __SPI_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
 	    													  
void SPI1_Init(void);			 //��ʼ��SPI1��
void SPI1_Setclock(u8 SPI_Prescaler); //����SPI1ʱ���ٶ�   
u8 SPI1_ReadWriteByte(u8 writeData);  //SPI1���߶�дһ���ֽ�
		 
#endif

