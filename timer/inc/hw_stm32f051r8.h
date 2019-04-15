#ifndef __HW_STM32F051R8_H__
#define __HW_STM32F051R8_H__
#include"hw_rcc.h"
#include"hw_gpio.h"
#include"hw_exti.h"
#include"hw_lcd1602.h"
#include"hw_uart.h"
/*--------------NVIC Control ------------------*/
#define NVIC_ISER					(*(volatile unsigned long *)(0xE000E100u))
#define NVIC_ICER					(*(volatile unsigned long *)(0xE000E180u))
#define NVIC_ISPR					(*(volatile unsigned long *)(0xE000E200u))
#define NVIC_ICPR					(*(volatile unsigned long *)(0xE000E280u))
/*---------------reg set priority--------------*/
#define NVIC_PRI0					(*(volatile unsigned long *)(0xE000E400u))
#define NVIC_PRI1					(*(volatile unsigned long *)(0xE000E404u))
#define NVIC_PRI2					(*(volatile unsigned long *)(0xE000E408u))
#define NVIC_PRI3					(*(volatile unsigned long *)(0xE000E40Cu))
#define NVIC_PRI4					(*(volatile unsigned long *)(0xE000E410u))
#define NVIC_PRI5					(*(volatile unsigned long *)(0xE000E414u))
#define NVIC_PRI6					(*(volatile unsigned long *)(0xE000E418u))
#define NVIC_PRI7					(*(volatile unsigned long *)(0xE000E41Cu))
/*-------------------reg SYSCFG------------------*/
#define SYSCFG_BASE					0x40010000u
#define SYSCFG_EXTICR1				(*(volatile unsigned long *)(SYSCFG_BASE + 0x08u))
/*--------------------System Timer---------------*/
#define SYST_CSR					(*(volatile unsigned long *)(0xE000E010u))
#define SYST_RVR					(*(volatile unsigned long *)(0xE000E014u))
#define SYST_CVR					(*(volatile unsigned long *)(0xE000E018u))
#define SYST_CALIB					(*(volatile unsigned long *)(0xE000E01Cu))
#endif

