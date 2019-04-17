#ifndef __SW_DELAY_H__
#define __SW_DELAY_H__
#include"hw_stm32f051r8.h"
void systick_init();
void start_timer(unsigned int value);
unsigned int get_state_systick();
void delay_us(unsigned int value);
void delay_ms(unsigned int value);
void delay_s(unsigned int value);
#endif
