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
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);   //使能串口外设
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);	 //使能输出端口
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);	 //使能输出端口

    GPIO_PinAFConfig(GPIOC,GPIO_PinSource12,GPIO_AF_UART5);   //连接端口与外设
    GPIO_PinAFConfig(GPIOD,GPIO_PinSource2,GPIO_AF_UART5);    //连接端口与外设


    GPIO_InitStructe.GPIO_Mode=GPIO_Mode_AF;                  //模式设置为复用
    GPIO_InitStructe.GPIO_OType=GPIO_OType_PP;                //强制推挽输出提高数据准确性
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_2;                     //输出引脚为2
    GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_UP;                  //为了减少数据传输的损失特设上拉！！
    GPIO_InitStructe.GPIO_Speed=GPIO_High_Speed;              //设置为高速提高传递效率
    GPIO_Init(GPIOD,&GPIO_InitStructe);
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_12;                    //输出引脚为2
    GPIO_Init(GPIOC,&GPIO_InitStructe);	

		USART_InitStructe.USART_BaudRate = bount;                                     //波特率设置
		USART_InitStructe.USART_WordLength = USART_WordLength_8b;                     //字长为8位数据格式
		USART_InitStructe.USART_StopBits = USART_StopBits_1;                          //一个停止位
		USART_InitStructe.USART_Parity = USART_Parity_No;                             //无奇偶校验位
		USART_InitStructe.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件数据流控制
		USART_InitStructe.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	                //收发模式
		USART_Init(UART5, &USART_InitStructe);                                        //初始化串口5
	
    USART_Cmd(UART5,ENABLE);                                                      //使能串口---开启串口通信
		USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);//开启相关中断

		//Usart1 NVIC 配置
		NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;//串口1中断通道
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
		NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;		//子优先级3
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
		NVIC_Init(&NVIC_InitStructure);											//根据指定的参数初始化VIC寄存器、
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
    va_list ap;                                 //定义一个可变参数
    int val,r_val;
    char count,ch;
    char *s=NULL;
    int res=0;																	//返回值

    va_start(ap,str);                         //初始化ap
    while('\0'!=*str)                    //str为字符串，他的最后一个肯定为‘\0’
    {
        switch(*str)
        {
        case '%':               //识别到参数准备发送
            str++;
            switch(*str)
            {
            case 'd':             //十进制输出
                val=va_arg(ap,int);
                r_val=val;
                count=0;
                while(r_val)
                {
                    count++;            //获取整数长度
                    r_val/=10;
                }
                res+=count;             //返回值长度增加
                r_val=val;
                while(count)
                {
                    ch=r_val/m_pow(10,count-1);
                    r_val%=m_pow(10,count-1);
                    putchar_s(ch+'0');       //数字转换到字符准备输出
                    count--;
                }
                break;
            case 'x':     //16进制输出
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
	for (int i = 0,j=0;u->str[i] != '\0';i++)					        			//str循环处理
	{
		if (u->str[i] == 'x'&&u->str[i - 1] != 'v')										//判断标志位
		{
			i++;																												//自增一移动一位
			for (j = 0;u->str[i] != 'y';j++, i++)u->x[j] = u->str[i];		//循环接收字符串
			u->x[j] = '\0';																							//结尾加上空操作符
   	}
		if (u->str[i] == 'y'&&u->str[i - 1] != 'v')										//判断标志位
		{
			i++;														                            //自增一移动一位
			for (j = 0;u->str[i] != 'v';j++, i++)  u->y[j] = u->str[i]; //循环接收字符串
			u->y[j] = '\0';																							//结尾加上空字符
		}
		if (u->str[i] == 'v'&&u->str[i+1] == 'x')											//判断标志位
		{
			i+=2;																												//移动两位
			for (j = 0;u->str[i] != 'v';j++, i++)u->Vx[j] = u->str[i];  //循环接收字符串
			u->Vx[j] = '\0';																						//结尾加上空字符
		}
		if (u->str[i] == 'v'&&u->str[i+1] == 'y')											//判断标志位
		{
			i+=2;																												//移动两位
			for (j = 0;u->str[i] != 'e';j++, i++)u->Vy[j] = u->str[i];	//循环接收字符串
			u->Vy[j] = '\0';																						//结尾加上空字符
		}
	}
 }
}
K  k={0,0,0,0};                                                       //建立外部区域
void UART5_IRQHandler(void)                               	//串口1中断服务程序
{
    static USART_RV   u;                                     //建立接受区域
	  static short state=0;                                    //判断接受状态并赋初值为0   （0关闭 ， 1开启接收数组， 2开启处理字符串,3开始转换字符串转换数字）
	  static int i=0;                                            //接收变量
	  static double last[2];
    if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)     //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	  {
		  u.ch=USART_ReceiveData(UART5);                          //(UART5->DR);	//读取接收到的数据
			if(u.ch=='p') state=1;                            			//如果接收到开始字符则开始接收字符串
			if(state==1)                                            //字符串接收处理
			{   
			  u.str[i++]=u.ch;                                    //开始接收字符串	
					if(i>=22)
					{
						state=0;
						i=0;
						printf_s("ok");
					}				
			  if(u.ch=='e')
				{                                                          //接收到截止字符
					if(i>=22)
					{
						state=0;
						i=0;
						printf_s("ok");
					}
					else
					{
						u.str[i]='\0';
						state=2;                                         //添加空操作字符
					}
					                                  
			  }
				if(state==2)                                          //开始处理数组
				{
				  str_cut(&u);                                        //处理字符串函数
					state=3;                                            //将字符串转换为数字模式开启
					
				}
				if(state==3)
				{ 
				k.x=atof(u.x);                                         //链接
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



