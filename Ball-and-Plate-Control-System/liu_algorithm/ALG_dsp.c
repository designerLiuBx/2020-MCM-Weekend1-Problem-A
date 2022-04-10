#include "ALG_dsp.h"
#include "Gen_include.h"
/*
t  : ǰ���뱳���ķָ���ֵ
w0 : ǰ������ռͼ�����
u0 : ǰ��ƽ���Ҷ�
w1 : ��������ռͼ�����
u1 : ����ƽ���Ҷ�
u  : ͼ����ƽ���Ҷ�  w0*u0+w1*u1
����С�Ҷȵ����Ҷȱ���t, ��tʹ�� g=w0*(u0-u2)2+w1*(u1-u)2 ���ʱ �����ֵ   g=w0*w1*(u0-u1)2
��
*/

void RGB2GRAY(void)
{
;
}
	
int my_Otsu(int Image[Height][Width])
{
	int x=0, y=0, piexlMin=0, piexlMax=0;
	int pixelCount[256];
	float pixelPro[256];
	int i, j, pixelSum=Width*Height, threshold=0;
	float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;

	
  for(i = 0; i<256; i++)
	{
		pixelCount[i]=0;
		pixelPro[i]=0;	
	}
	for (i = y; i <Height;i++)	//ͳ�Ƹ�������������ͼ��ĸ���
		for(j = x; i<Width; j++)
				pixelCount[Image[i][j]]++;
	for (i = 0; i<256; i++)	      //����ÿ������������ͼ���еı���
		pixelPro[i] = (float)(pixelCount[i]) / (float)(pixelSum);
	for (i = 0; i<256; i++)
			if(pixelPro[i] != 0)
					piexlMin = i;
	for (i = 255; i>=0; i--)
			if(pixelPro[i] != 0)
					piexlMax=i;
	//OTSU
	for(i = piexlMin; i<=piexlMax; i++)
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for (j = 0; j < 256; j++)
		{
			if (j <= i) //��������
			{
				//��iΪ��ֵ���࣬��һ���ܵĸ���
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else       //ǰ������
			{
				//��iΪ��ֵ���࣬�ڶ����ܵĸ���
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		
    u0 = u0tmp / w0;		//��һ���ƽ���Ҷ�
		u1 = u1tmp / w1;		//�ڶ����ƽ���Ҷ�
		u = u0tmp + u1tmp;		//����ͼ���ƽ���Ҷ�
		deltaTmp = w0 * (u0 - u)*(u0 - u) + w1 * (u1 - u)*(u1 - u);		//������䷽��
		
   	if (deltaTmp > deltaMax)    		//�ҳ������䷽���Լ���Ӧ����ֵ
		{
			deltaMax = deltaTmp;
			threshold = i;
		}
	}
	return threshold;	
}

void ImageBinarization(int Image[Height][Width])
{
	int i,j;
	int threshold;
	
	threshold = my_Otsu(Image);
	for(i=0;i<Height;i++)
		for(j=0;j<Width;j++)
			{
				if(Image[i][j]>threshold)
					Image[i][j]=255;
				else
					Image[i][j]=0;
			}
}	
void FxedPosition(int Image[Height][Width])
{
	int i, j;
	
	basePoint.y=Height/2;
	basePoint.x=Width/2;
	ballPoint.yMax=0;
  ballPoint.xMax=0;
  ballPoint.yMin=Height;
	ballPoint.xMin=Width;

	for(i=0;i<Height;i++)
	{	for(j=0;j<Width;j++)
		{
			if(Image[j][i]==0)
			{
				ballPoint.y = i;
				ballPoint.x = j;
			}
	    ballPoint.yMax=(ballPoint.y>ballPoint.yMax)?ballPoint.y:ballPoint.yMax;
			ballPoint.yMin=(ballPoint.y<ballPoint.yMax)?ballPoint.y:ballPoint.yMax;
	    ballPoint.xMax=(ballPoint.x>ballPoint.xMax)?ballPoint.x:ballPoint.xMax;
	    ballPoint.xMin=(ballPoint.x<ballPoint.xMax)?ballPoint.x:ballPoint.xMax;	
		}
	}
	ballPoint.ball_y=(ballPoint.yMax+ballPoint.yMax)/2;
	ballPoint.ball_x=(ballPoint.xMax+ballPoint.xMax)/2;
}








