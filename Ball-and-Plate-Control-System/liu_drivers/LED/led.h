#ifndef __LED_H
#define __LED_H
#include "sys.h"
#define LED0 PGout(13)	
#define LED1 PGout(14)	 
#define LED2 PGout(15)


void LED_Init(void);
#endif
