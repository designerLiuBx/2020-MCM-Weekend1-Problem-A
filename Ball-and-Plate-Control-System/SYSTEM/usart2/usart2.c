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

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);   //ʹ�ܴ�������
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);				//ʹ������˿�

    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);   //���Ӷ˿�������
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2);   //���Ӷ˿�������

    GPIO_InitStructe.GPIO_Mode=GPIO_Mode_AF;                  //ģʽ����Ϊ����
    GPIO_InitStructe.GPIO_OType=GPIO_OType_PP;             //ǿ����������������׼ȷ��
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;    //�������Ϊ5��6
    GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_UP;                 //Ϊ�˼������ݴ������ʧ������������
    GPIO_InitStructe.GPIO_Speed=GPIO_High_Speed;          //����Ϊ������ߴ���Ч��
    GPIO_Init(GPIOA,&GPIO_InitStructe);
	
  

		USART_InitStructe.USART_BaudRate = bount;//����������
		USART_InitStructe.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
		USART_InitStructe.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
		USART_InitStructe.USART_Parity = USART_Parity_No;//����żУ��λ
		USART_InitStructe.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
		USART_InitStructe.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
		USART_Init(USART2, &USART_InitStructe); //��ʼ������1
	
    USART_Cmd(USART2,ENABLE);                   //ʹ�ܴ���---��������ͨ��
}

