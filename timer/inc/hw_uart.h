#ifndef __HW_UART_H__
#define __HW_UART_H__
#define USART1_BASE			0x40013800u
/*----------------------------USART1--------------------------------------*/
#define USART1_CR1			*((volatile unsigned long*)(USART1_BASE + 0x00))
#define USART1_CR2			*((volatile unsigned long*)(USART1_BASE + 0x04))
#define USART1_CR3			*((volatile unsigned long*)(USART1_BASE + 0x08))
#define USART1_BRR			*((volatile unsigned long*)(USART1_BASE + 0x0C))
#define USART1_GTPR			*((volatile unsigned long*)(USART1_BASE + 0x10))
#define USART1_RTOR			*((volatile unsigned long*)(USART1_BASE + 0x14))
#define USART1_RQR			*((volatile unsigned long*)(USART1_BASE + 0x18))
#define USART1_ISR			*((volatile unsigned long*)(USART1_BASE + 0x1C))
#define USART1_ICR			*((volatile unsigned long*)(USART1_BASE + 0x20))
#define USART1_RDR			*((volatile unsigned long*)(USART1_BASE + 0x24))
#define USART1_TDR			*((volatile unsigned long*)(USART1_BASE + 0x28))
/*----------------------------USART2--------------------------------------*/

#endif