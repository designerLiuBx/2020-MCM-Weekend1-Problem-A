#ifndef _DSP_H_
#define _DSP_H_

#include "sys.h"
#include "Gen_include.h"
#define Height 480
#define Width  680

void RGB2GRAY(void);
int my_Otsu(int Image[Height][Width]);
void ImageBinarization(int Image[Height][Width]);
#endif

