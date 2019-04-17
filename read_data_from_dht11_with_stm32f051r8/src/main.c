#include"hw_stm32f051r8.h"
#include"sw_rcc.h"
#include"sw_gpio.h"
#include"sw_interrupt.h"
#include"sw_delay.h"
#include"sw_lcd1602.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sw_uart.h"
/*
	___________DHT11_________
	-----DATA------------PC5
	___________LCD___________
	-----EN---------------PC6
	-----RS---------------PC7
	-----D4---------------PC8
	-----D5---------------PC9
*/
void dht11_start(){
	GPIO_setmode('C',5,1);
	GPIO_setbit('C',5);
	GPIO_resetbit('C',5);
	delay_ms(18);
	GPIO_setbit('C',5);
	GPIO_setmode('C',5,0);
	delay_us(3);
}
int I_RH,D_RH,I_Temp,D_Temp,CheckSum;
int respone(){
	if(0==GPIO_readpin('C',5)){
		while(0==GPIO_readpin('C',5));
		while(1==GPIO_readpin('C',5));
	}
	else{
		lcd_Clear();
		lcd_puts("error");
		return 0;
	}
	return 1;
}
int Receive_data(){
	int q,c=0;	
	for (q=0; q<8; q++)
	{
		while(0==GPIO_readpin('C',5));
		delay_us(4);
		if(GPIO_readpin('C',5)==1){
			c = (c<<1)|(0x01);
		}
		else{
			c = (c<<1);
		}
		while(1==GPIO_readpin('C',5));
	}
	return c;	
}

int main(){
	char Data[40];
	RCC_HSE_init();
	RCC_Usart_init();
	systick_init();
	RCC_EnClkIOport('A');
	RCC_EnClkIOport('C');
	init_pin();
	lcd_Init();
	lcd_Clear();
	lcd_gotoxy(0,0);
	Usart1_Init();
	while(1){
	    dht11_start();
		respone();
		I_RH=Receive_data();	/* store first eight bit in I_RH */		
		D_RH=Receive_data();	/* store next eight bit in D_RH */	
		I_Temp=Receive_data();	/* store next eight bit in I_Temp */
		D_Temp=Receive_data();	/* store next eight bit in D_Temp */
		CheckSum=Receive_data();/* store next eight bit in CheckSum */
		if(CheckSum == I_RH + D_RH + I_Temp + D_Temp){
			lcd_Clear();
			lcd_gotoxy(0,0);
			sprintf(Data,"Hum: %d.%d",I_RH,D_RH);
			lcd_puts(Data);
			lcd_gotoxy(0,1);
			sprintf(Data,"Temp: %d.%d",I_Temp,D_Temp);
			lcd_puts(Data);
			sprintf(Data,"%d_%d\n",I_Temp,I_RH);
			Usart1_send_string(Data);
		}
		else{
			lcd_Clear();
			lcd_gotoxy(5,0);
			lcd_puts("Fail!!");
		}
		delay_ms(1500);
	}
}
void RCC_IRQHandler(){
	//RCC_CIR->HSERDYF(bit 3)
	if((RCC_CIR & (1<<3))!=0){
		//RCC_CIR->HSERDYC(bit 19) xoa co ngat
		RCC_CIR |= (1<<19);
		//chuyen doi thanh muc HSEON(bit[1:0])
		RCC_CFGR &= ~(0x3<<0);
		RCC_CFGR |= (0x01<<0);
		__asm("cpsid i");//tat cac ngat toan cuc
	}
}
void USART1_IRQHandler(){
}
void SystemInit(){
	RCC_CR |= 0x00000001u;
    RCC_CFGR &= 0xF8FFB80Cu;
  /* Reset HSEON, CSSON and PLLON bits */
    RCC_CR &= 0xFEF6FFFFU;
  /* Reset HSEBYP bit */
    RCC_CR &= 0xFFFBFFFFU;
  /* Reset PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
  	RCC_CFGR &= 0xFFC0FFFFU;
  /* Reset PREDIV[3:0] bits */
    RCC_CFGR &= 0xFFFFFFF0U;
  //   Reset USART1SW[1:0], I2C1SW, CECSW and ADCSW bits 
    RCC_CFGR3 &= 0xFFFFFEACU;
  /* Reset USART1SW[1:0], I2C1SW, USBSW and ADCSW bits */
    RCC_CFGR3 &= 0xFFFFFE6CU;
   // Set default USB clock to PLLCLK, since there is no HSI48 
    RCC_CFGR3 |= 0x00000080u; 
   // /* Reset HSI14 bit */
    RCC_CR2 &= 0xFFFFFFFEu;
   // Disable all interrupts 
    RCC_CIR = 0x00000000u;
}

