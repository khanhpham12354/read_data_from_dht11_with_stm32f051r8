#ifndef __HW_EXTI_H__
#define __HW_EXTI_H__

#define EXTI_BASE			0x40010400u
#define EXTI_IMR			(*(volatile unsigned long *)(EXTI_BASE + 0x00u))
#define EXTI_EMR			(*(volatile unsigned long *)(EXTI_BASE + 0x04u))
#define EXTI_RTSR			(*(volatile unsigned long *)(EXTI_BASE + 0x08u))
#define EXTI_FTSR			(*(volatile unsigned long *)(EXTI_BASE + 0x0Cu))
#define EXTI_SWIER			(*(volatile unsigned long *)(EXTI_BASE + 0x10u))
#define EXTI_PR  			(*(volatile unsigned long *)(EXTI_BASE + 0x14u))
#endif

