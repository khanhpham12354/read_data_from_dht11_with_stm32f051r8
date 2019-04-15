#ifndef __HW_RCC_H__
#define __HW_RCC_H__
/*--------------------------Base address-----------------------------------*/
#define RCC_BASE					0x40021000u
/*--------------------------------------------------------------------------*/
#define RCC_CR				  (*(volatile unsigned long *)(RCC_BASE + 0x00u))
#define RCC_CFGR			  (*(volatile unsigned long *)(RCC_BASE + 0x04u))
#define RCC_CIR 			  (*(volatile unsigned long *)(RCC_BASE + 0x08u))
#define RCC_APB2RSTR          (*(volatile unsigned long *)(RCC_BASE + 0x0Cu))
#define RCC_APB1RSTR		  (*(volatile unsigned long *)(RCC_BASE + 0x10u))
#define RCC_AHBENR			  (*(volatile unsigned long *)(RCC_BASE + 0x14u))
#define RCC_APB2ENR           (*(volatile unsigned long *)(RCC_BASE + 0x18u))
#define RCC_APB1ENR           (*(volatile unsigned long *)(RCC_BASE + 0x1Cu))
#define RCC_BDCR			  (*(volatile unsigned long *)(RCC_BASE + 0x20u))
#define RCC_CSR				  (*(volatile unsigned long *)(RCC_BASE + 0x24u))
#define RCC_AHBRSTR           (*(volatile unsigned long *)(RCC_BASE + 0x28u))
#define RCC_CFGR2             (*(volatile unsigned long *)(RCC_BASE + 0x2Cu))
#define RCC_CFGR3             (*(volatile unsigned long *)(RCC_BASE + 0x30u))
#define RCC_CR2               (*(volatile unsigned long *)(RCC_BASE + 0x34u))
#endif

