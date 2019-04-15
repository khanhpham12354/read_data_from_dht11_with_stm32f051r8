#include"sw_lcd1602.h"
/*Khoi tao cho LCD */
void init_pin(){
	RCC_EnClkIOport('C');
	GPIO_setmode('C',RS,1);
	GPIO_setmode('C',E,1);
	GPIO_setmode('C',DB4,1);
	GPIO_setmode('C',DB5,1);
	GPIO_setmode('C',DB6,1);
	GPIO_setmode('C',DB7,1);
}
void lcd_Enable(){
	GPIO_setbit('C',E);
	delay_us(3);
	GPIO_resetbit('C',E);
	delay_us(50);	
}
void lcd_send4bit(unsigned char data){
	unsigned int temp = 0;
	/*DB4*/
	temp = (data & 0x01);
	if(1 == temp){
		GPIO_setbit('C',DB4);
	}
	else{
		GPIO_resetbit('C',DB4);
	}
	/*DB5*/
	temp = (data>>1) & 0x01;
	if(1 == temp){
		GPIO_setbit('C',DB5);
	}
	else{
		GPIO_resetbit('C',DB5);
	}
	/*DB6*/
	temp = (data>>2) & 0x01;
	if(1 == temp){
		GPIO_setbit('C',DB6);
	}
	else{
		GPIO_resetbit('C',DB6);
	}
	/*DB7*/
	temp = (data>>3) & 0x01;
	if(1 == temp){
		GPIO_setbit('C',DB7);
	}
	else{
		GPIO_resetbit('C',DB7);
	}
}
void lcd_sendCommand(unsigned char cmd){
	lcd_send4bit(cmd>>4);
	lcd_Enable();
	lcd_send4bit(cmd);
	lcd_Enable();
}
void lcd_Clear(){
	lcd_sendCommand(0x01);
	delay_us(10);
}
void lcd_Init(){
	lcd_send4bit(0x00);//bat lcd
	delay_ms(20);
	GPIO_resetbit('C',RS);
	lcd_send4bit(0x03);
	lcd_Enable();
	delay_ms(10);
	lcd_Enable();
	delay_us(5);
	lcd_send4bit(0x02);
	lcd_Enable();
	lcd_sendCommand(0x28);
	lcd_sendCommand(0x0C);
	lcd_sendCommand(0x06);
	lcd_sendCommand(0x01);
}
void lcd_gotoxy(unsigned char x,unsigned char y){
	/*x la cot y la hang*/
	unsigned char address;
	if(!y) address = (0x80 + x);
	else address = (0xC0 + x);
	delay_ms(1);
	lcd_sendCommand(address);
	delay_us(50);
}
void lcd_putchar(unsigned char data){
	GPIO_setbit('C',RS);
	lcd_sendCommand(data);
	GPIO_resetbit('C',RS);
}
void lcd_puts(char *str){
	while(*str){
		lcd_putchar(*str);
		str++;
	}
}