#ifndef __SW_LCD1602_H__
#define __SW_LCD1602_H__
#include"hw_stm32f051r8.h"
#include"sw_delay.h"
#include"sw_gpio.h"
#include"sw_rcc.h"
void init_pin();
void lcd_Init();
void lcd_Enable();
void lcd_send4bit(unsigned char data);
void lcd_sendCommand(unsigned char cmd);
void lcd_Clear();
void lcd_gotoxy(unsigned char x,unsigned char y);
void lcd_putchar(unsigned char data);
void lcd_puts(char *str);

#endif