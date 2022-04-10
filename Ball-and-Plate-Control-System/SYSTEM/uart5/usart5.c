#include "sys.h"
#include "usart5.h"
#include "stdarg.h"
#include <string.h>
#include <stdlib.h>
/*********************************************************************************************************************************************************
*************************************************************************7  0   6*************************************************************************
**********************************************************************************************************************************************************/


void uart5_init(u32 bount)
{
    GPIO_InitTypeDef  GPIO_InitStructe;
    USART_InitTypeDef  USART_InitStructe;
	  NVIC_InitTypeDef NVIC_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);   //ʹ�ܴ�������
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);	 //ʹ������˿�
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);	 //ʹ������˿�

    GPIO_PinAFConfig(GPIOC,GPIO_PinSource12,GPIO_AF_UART5);   //���Ӷ˿�������
    GPIO_PinAFConfig(GPIOD,GPIO_PinSource2,GPIO_AF_UART5);    //���Ӷ˿�������


    GPIO_InitStructe.GPIO_Mode=GPIO_Mode_AF;                  //ģʽ����Ϊ����
    GPIO_InitStructe.GPIO_OType=GPIO_OType_PP;                //ǿ����������������׼ȷ��
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_2;                     //�������Ϊ2
    GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_UP;                  //Ϊ�˼������ݴ������ʧ������������
    GPIO_InitStructe.GPIO_Speed=GPIO_High_Speed;              //����Ϊ������ߴ���Ч��
    GPIO_Init(GPIOD,&GPIO_InitStructe);
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_12;                    //�������Ϊ2
    GPIO_Init(GPIOC,&GPIO_InitStructe);	

		USART_InitStructe.USART_BaudRate = bount;                                     //����������
		USART_InitStructe.USART_WordLength = USART_WordLength_8b;                     //�ֳ�Ϊ8λ���ݸ�ʽ
		USART_InitStructe.USART_StopBits = USART_StopBits_1;                          //һ��ֹͣλ
		USART_InitStructe.USART_Parity = USART_Parity_No;                             //����żУ��λ
		USART_InitStructe.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ������������
		USART_InitStructe.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	                //�շ�ģʽ
		USART_Init(UART5, &USART_InitStructe);                                        //��ʼ������5
	
    USART_Cmd(UART5,ENABLE);                                                      //ʹ�ܴ���---��������ͨ��
		USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);//��������ж�

		//Usart1 NVIC ����
		NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;//����1�ж�ͨ��
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
		NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;		//�����ȼ�3
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
		NVIC_Init(&NVIC_InitStructure);											//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
}

static unsigned long m_pow(int  x,int  y)
{
    unsigned long sum=1;
    while(y--)
    {
        sum*=x;
    }
    return sum;
}
void putchar_s(const char ch)
{
    while(RESET==USART_GetFlagStatus(UART5,USART_FLAG_TC)) {;}
    USART_SendData(UART5,ch);
}
void put_s(const char *str)
{
    while(*str)
    {
        putchar_s(*str++);
    }
}
char *get_s(char *p)
{
    int i=0;
	
  h:
     if(USART_GetITStatus(UART5,USART_IT_RXNE)==RESET)
    {

       *(p+i) =USART_ReceiveData(UART5);
			if( *(p+i)!=';')
			{
				i++;
				goto h;
			}				
				return p;
    }
     else
  {
    return NULL;
	}
}
int printf_s(const char *str,...)
{
    va_list ap;                                 //����һ���ɱ����
    int val,r_val;
    char count,ch;
    char *s=NULL;
    int res=0;																	//����ֵ

    va_start(ap,str);                         //��ʼ��ap
    while('\0'!=*str)                    //strΪ�ַ������������һ���϶�Ϊ��\0��
    {
        switch(*str)
        {
        case '%':               //ʶ�𵽲���׼������
            str++;
            switch(*str)
            {
            case 'd':             //ʮ�������
                val=va_arg(ap,int);
                r_val=val;
                count=0;
                while(r_val)
                {
                    count++;            //��ȡ��������
                    r_val/=10;
                }
                res+=count;             //����ֵ��������
                r_val=val;
                while(count)
                {
                    ch=r_val/m_pow(10,count-1);
                    r_val%=m_pow(10,count-1);
                    putchar_s(ch+'0');       //����ת�����ַ�׼�����
                    count--;
                }
                break;
            case 'x':     //16�������
                val=va_arg(ap,int);
                r_val=val;
                count=0;
                while(r_val)
                {
                    count++;
                    r_val/=16;
                }
                res+=count;
                r_val=val;
                while(count)
                {
                    ch=r_val/m_pow(16,count-1);
                    r_val%=m_pow(16,count-1);
                    if(ch<=9)
                        putchar_s(ch+'0');
                    else
                        putchar_s(ch-10+'a');
                    count--;
                }
                break;
            case's':
                s=va_arg(ap,char  *);
                put_s(s);
                res+=strlen(s);
                break;
            case 'c':
                putchar_s((char)va_arg(ap,int));
                res+=1;
                break;
            default:
                ;
            }
        case '\n':
            putchar_s('\n');
            res+=1;
            break;
        case '\r':
            putchar_s('\r');
            res+=1;
            break;
        default:
            putchar_s(*str);
            res+=1;
        }
        str++;
    }
    va_end(ap);
    return res;
}

void str_cut(USART_RV *u)
{
	static int t=0;
	if(t==0)
	{
	for (int i = 0,j=0;u->str[i] != '\0';i++)					        			//strѭ������
	{
		if (u->str[i] == 'x'&&u->str[i - 1] != 'v')										//�жϱ�־λ
		{
			i++;																												//����һ�ƶ�һλ
			for (j = 0;u->str[i] != 'y';j++, i++)u->x[j] = u->str[i];		//ѭ�������ַ���
			u->x[j] = '\0';																							//��β���Ͽղ�����
   	}
		if (u->str[i] == 'y'&&u->str[i - 1] != 'v')										//�жϱ�־λ
		{
			i++;														                            //����һ�ƶ�һλ
			for (j = 0;u->str[i] != 'v';j++, i++)  u->y[j] = u->str[i]; //ѭ�������ַ���
			u->y[j] = '\0';																							//��β���Ͽ��ַ�
		}
		if (u->str[i] == 'v'&&u->str[i+1] == 'x')											//�жϱ�־λ
		{
			i+=2;																												//�ƶ���λ
			for (j = 0;u->str[i] != 'v';j++, i++)u->Vx[j] = u->str[i];  //ѭ�������ַ���
			u->Vx[j] = '\0';																						//��β���Ͽ��ַ�
		}
		if (u->str[i] == 'v'&&u->str[i+1] == 'y')											//�жϱ�־λ
		{
			i+=2;																												//�ƶ���λ
			for (j = 0;u->str[i] != 'e';j++, i++)u->Vy[j] = u->str[i];	//ѭ�������ַ���
			u->Vy[j] = '\0';																						//��β���Ͽ��ַ�
		}
	}
 }
}
K  k={0,0,0,0};                                                       //�����ⲿ����
void UART5_IRQHandler(void)                               	//����1�жϷ������
{
    static USART_RV   u;                                     //������������
	  static short state=0;                                    //�жϽ���״̬������ֵΪ0   ��0�ر� �� 1�����������飬 2���������ַ���,3��ʼת���ַ���ת�����֣�
	  static int i=0;                                            //���ձ���
	  static double last[2];
    if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)     //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	  {
		  u.ch=USART_ReceiveData(UART5);                          //(UART5->DR);	//��ȡ���յ�������
			if(u.ch=='p') state=1;                            			//������յ���ʼ�ַ���ʼ�����ַ���
			if(state==1)                                            //�ַ������մ���
			{   
			  u.str[i++]=u.ch;                                    //��ʼ�����ַ���	
					if(i>=22)
					{
						state=0;
						i=0;
						printf_s("ok");
					}				
			  if(u.ch=='e')
				{                                                          //���յ���ֹ�ַ�
					if(i>=22)
					{
						state=0;
						i=0;
						printf_s("ok");
					}
					else
					{
						u.str[i]='\0';
						state=2;                                         //��ӿղ����ַ�
					}
					                                  
			  }
				if(state==2)                                          //��ʼ��������
				{
				  str_cut(&u);                                        //�����ַ�������
					state=3;                                            //���ַ���ת��Ϊ����ģʽ����
					
				}
				if(state==3)
				{ 
				k.x=atof(u.x);                                         //����
				k.y=atof(u.y);
				k.Vx=atof(u.Vx)*0.05909;
				k.Vy=atof(u.Vy)*0.05909;
					/*
					
					*/
				if(k.Vx>0.65) k.Vx=last[0];
				if(k.Vy>0.65) k.Vy=last[1];
				state=0;
				i=0;
				printf_s("ok");
				last[0]= k.Vx;
				last[1]=k.Vy;
				}	
		  }
     }
}	



