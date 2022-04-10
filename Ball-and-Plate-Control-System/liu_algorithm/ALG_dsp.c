#include "ALG_dsp.h"
#include "Gen_include.h"
/*
t  : 前景与背景的分割阈值
w0 : 前景点数占图像比例
u0 : 前景平均灰度
w1 : 背景点数占图像比例
u1 : 背景平均灰度
u  : 图像总平均灰度  w0*u0+w1*u1
从最小灰度到最大灰度遍历t, 当t使得 g=w0*(u0-u2)2+w1*(u1-u)2 最大时 即最佳值   g=w0*w1*(u0-u1)2
阈
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
	for (i = y; i <Height;i++)	//统计各个像素在整个图像的个数
		for(j = x; i<Width; j++)
				pixelCount[Image[i][j]]++;
	for (i = 0; i<256; i++)	      //计算每个像素在整幅图像中的比例
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
			if (j <= i) //背景部分
			{
				//以i为阈值分类，第一类总的概率
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else       //前景部分
			{
				//以i为阈值分类，第二类总的概率
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		
    u0 = u0tmp / w0;		//第一类的平均灰度
		u1 = u1tmp / w1;		//第二类的平均灰度
		u = u0tmp + u1tmp;		//整幅图像的平均灰度
		deltaTmp = w0 * (u0 - u)*(u0 - u) + w1 * (u1 - u)*(u1 - u);		//计算类间方差
		
   	if (deltaTmp > deltaMax)    		//找出最大类间方差以及对应的阈值
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








