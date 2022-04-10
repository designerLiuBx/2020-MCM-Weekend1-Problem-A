#include "sys.h"
#include "usart2.h"
#include "stdarg.h"
#include <string.h>
#include <stdlib.h>
/*********************************************************************************************************************************************************
*************************************************************************7  0   6*************************************************************************
**********************************************************************************************************************************************************/
void uart2_init(u32 bount)
{
    GPIO_InitTypeDef  GPIO_InitStructe;
    USART_InitTypeDef  USART_InitStructe;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);   //使能串口外设
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);				//使能输出端口

    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);   //连接端口与外设
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2);   //连接端口与外设

    GPIO_InitStructe.GPIO_Mode=GPIO_Mode_AF;                  //模式设置为复用
    GPIO_InitStructe.GPIO_OType=GPIO_OType_PP;             //强制推挽输出提高数据准确性
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;    //输出引脚为5和6
    GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_UP;                 //为了减少数据传输的损失特设上拉！！
    GPIO_InitStructe.GPIO_Speed=GPIO_High_Speed;          //设置为高速提高传递效率
    GPIO_Init(GPIOA,&GPIO_InitStructe);
	
  

		USART_InitStructe.USART_BaudRate = bount;//波特率设置
		USART_InitStructe.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
		USART_InitStructe.USART_StopBits = USART_StopBits_1;//一个停止位
		USART_InitStructe.USART_Parity = USART_Parity_No;//无奇偶校验位
		USART_InitStructe.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
		USART_InitStructe.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
		USART_Init(USART2, &USART_InitStructe); //初始化串口1
	
    USART_Cmd(USART2,ENABLE);                   //使能串口---开启串口通信
}

