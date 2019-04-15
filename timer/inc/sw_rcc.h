#ifndef __SW_RCC_H__
#define __SW_RCC_H__
#include"hw_stm32f051r8.h"
#include"hw_rcc.h"
/*enable clock for port x=A..F*/
void RCC_EnClkIOport(unsigned char port);
void RCC_HSE_init();
void RCC_Usart_init();
#endif

