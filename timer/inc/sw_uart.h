#ifndef __SW_UART_H__
#define __SW_UART_H__
#include"hw_stm32f051r8.h"
#include"sw_gpio.h"
void Usart1_Init();
char Usart1_sendbyte(unsigned char data);
char Usart1_send_string(char *str_data);

#endif