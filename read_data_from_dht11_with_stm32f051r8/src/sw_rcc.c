#include"sw_rcc.h"
/*
	HSE 8MHz -> SYSCLK for UART1
	
*/
void RCC_HSE_init(){
	NVIC_PRI1 |= (0x00<<6);// set muc uu tien cho ngat
	NVIC_ISER |= (1<<4);// bat ngat RCC
	__asm("cpsie i");//bat ngat toan cuc
	RCC_CIR |= (1<<11);//HSERDYIE: HSE ready interrupt enable bit 11 cua RCC_CIR
	// bat CSSON(19) , HSEBYP(18) , HSEON(16)
	RCC_CR |=(1<<19)|(1<<18)|(1<<16);
}
void RCC_EnClkIOport(unsigned char port){
	switch(port){
		case 'A':
		   {	
			RCC_AHBENR |= (1<<17);
			break;
		   }
		case 'B':
			{
			RCC_AHBENR |= (1<<18);
			break;
			}
		case 'C':
			{
			RCC_AHBENR |= (1<<19);
			break;
			}
		case 'D':
			{
			RCC_AHBENR |= (1<<20);
			break;
			}
		case 'E':
			{
			RCC_AHBENR |= (1<<21);
			break;
			}
		case 'F':
			{
			RCC_AHBENR |= (1<<22);
			break;
			}
	 }
}

void RCC_Usart_init(){
	RCC_CFGR3 &= ~(0x3<<0);
	RCC_CFGR3 |= (1<<0);// set SYSCLK for UART1(8MHz)
	RCC_APB2ENR |=(1<<14);//enalble clock for USART1
}


