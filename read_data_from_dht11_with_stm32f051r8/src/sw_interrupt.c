#include"sw_interrupt.h"
void It_init(){
	EXTI_IMR |= (1<<0);
	SYSCFG_EXTICR1 |= (0x0<<0);
	EXTI_RTSR |= (1<<0);
	// enable NVIC
	NVIC_PRI1 |= (0x00<<14);
	NVIC_ISER |= (1<<5);
	__asm("cpsie i");
}
void It_usart1(){
	USART1_ICR = 0xFFFFFFFF;
	USART1_RQR = 0xFFFFFFFF;
	//enable ngat TX,RX
	USART1_CR1 |= (1<<6) |(1<<5);
	//set muc uu tien cho ngat nay
	NVIC_PRI6 |= (0x01<<30);
	//enable ngat trong NVIC
	NVIC_ISER |=(1<<27);
	//bat ngat toan cuc
	__asm("cpsie i");
}
