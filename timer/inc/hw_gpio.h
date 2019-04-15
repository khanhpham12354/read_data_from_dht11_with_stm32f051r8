#ifndef __HW_GPIO_H__
#define __HW_GPIO_H__
/*-----------------Base Add--------------------*/
#define	GPIO_A_BASE 				0x48000000u
#define	GPIO_B_BASE 				0x48000400u
#define	GPIO_C_BASE 				0x48000800u
#define	GPIO_D_BASE 				0x48000C00u
#define	GPIO_E_BASE 				0x48001000u
#define	GPIO_F_BASE 				0x48001400u
/*--------------------------------port A------------------------------------------*/
#define GPIO_A_MODER               (*(volatile unsigned long *)(GPIO_A_BASE + 0x00u))
#define GPIO_A_OTYPER			   (*(volatile unsigned long *)(GPIO_A_BASE + 0x04u))
#define GPIO_A_OSPEEDR             (*(volatile unsigned long *)(GPIO_A_BASE + 0x08u))
#define GPIO_A_PUPDR			   (*(volatile unsigned long *)(GPIO_A_BASE + 0x0Cu))
#define GPIO_A_IDR			       (*(volatile unsigned long *)(GPIO_A_BASE + 0x10u))
#define GPIO_A_ODR			       (*(volatile unsigned long *)(GPIO_A_BASE + 0x14u))
#define GPIO_A_BSRR				   (*(volatile unsigned long *)(GPIO_A_BASE + 0x18u))
#define GPIO_A_LCKR				   (*(volatile unsigned long *)(GPIO_A_BASE + 0x1Cu))
#define GPIO_A_AFRL				   (*(volatile unsigned long *)(GPIO_A_BASE + 0x20u))
#define GPIO_A_AFRH			       (*(volatile unsigned long *)(GPIO_A_BASE + 0x24u))
#define GIPO_A_BRR  			   (*(volatile unsigned long *)(GPIO_A_BASE + 0x28u))
/*--------------------------------port B------------------------------------------*/
#define GPIO_B_MODER               (*(volatile unsigned long *)(GPIO_B_BASE + 0x00u))
#define GPIO_B_OTYPER			   (*(volatile unsigned long *)(GPIO_B_BASE + 0x04u))
#define GPIO_B_OSPEEDR             (*(volatile unsigned long *)(GPIO_B_BASE + 0x08u))
#define GPIO_B_PUPDR			   (*(volatile unsigned long *)(GPIO_B_BASE + 0x0Cu))
#define GPIO_B_IDR			       (*(volatile unsigned long *)(GPIO_B_BASE + 0x10u))
#define GPIO_B_ODR			       (*(volatile unsigned long *)(GPIO_B_BASE + 0x14u))
#define GPIO_B_BSRR				   (*(volatile unsigned long *)(GPIO_B_BASE + 0x18u))
#define GPIO_B_LCKR				   (*(volatile unsigned long *)(GPIO_B_BASE + 0x1Cu))
#define GPIO_B_AFRL				   (*(volatile unsigned long *)(GPIO_B_BASE + 0x20u))
#define GPIO_B_AFRH			       (*(volatile unsigned long *)(GPIO_B_BASE + 0x24u))
#define GPIO_B_BRR  			   (*(volatile unsigned long *)(GPIO_B_BASE + 0x28u))
/*--------------------------------port C------------------------------------------*/
#define GPIO_C_MODER               (*(volatile unsigned long *)(GPIO_C_BASE + 0x00u))
#define GPIO_C_OTYPER			   (*(volatile unsigned long *)(GPIO_C_BASE + 0x04u))
#define GPIO_C_OSPEEDR             (*(volatile unsigned long *)(GPIO_C_BASE + 0x08u))
#define GPIO_C_PUPDR			   (*(volatile unsigned long *)(GPIO_C_BASE + 0x0Cu))
#define GPIO_C_IDR			       (*(volatile unsigned long *)(GPIO_C_BASE + 0x10u))
#define GPIO_C_ODR			       (*(volatile unsigned long *)(GPIO_C_BASE + 0x14u))
#define GPIO_C_BSRR				   (*(volatile unsigned long *)(GPIO_C_BASE + 0x18u))
#define GPIO_C_AFRL				   (*(volatile unsigned long *)(GPIO_C_BASE + 0x20u))
#define GPIO_C_AFRH			       (*(volatile unsigned long *)(GPIO_C_BASE + 0x24u))
#define GPIO_C_BRR  			   (*(volatile unsigned long *)(GPIO_C_BASE + 0x28u))
/*--------------------------------port D------------------------------------------*/
#define GPIO_D_MODER               (*(volatile unsigned long *)(GPIO_D_BASE + 0x00u))
#define GPIO_D_OTYPER			   (*(volatile unsigned long *)(GPIO_D_BASE + 0x04u))
#define GPIO_D_OSPEEDR             (*(volatile unsigned long *)(GPIO_D_BASE + 0x08u))
#define GPIO_D_PUPDR			   (*(volatile unsigned long *)(GPIO_D_BASE + 0x0Cu))
#define GPIO_D_IDR			       (*(volatile unsigned long *)(GPIO_D_BASE + 0x10u))
#define GPIO_D_ODR			       (*(volatile unsigned long *)(GPIO_D_BASE + 0x14u))
#define GPIO_D_BSRR				   (*(volatile unsigned long *)(GPIO_D_BASE + 0x18u))
#define GPIO_D_AFRL				   (*(volatile unsigned long *)(GPIO_D_BASE + 0x20u))
#define GPIO_D_AFRH			       (*(volatile unsigned long *)(GPIO_D_BASE + 0x24u))
#define GPIO_D_BRR  			   (*(volatile unsigned long *)(GPIO_D_BASE + 0x28u))
/*--------------------------------port E------------------------------------------*/
#define GPIO_E_MODER               (*(volatile unsigned long *)(GPIO_E_BASE + 0x00u))
#define GPIO_E_OTYPER			   (*(volatile unsigned long *)(GPIO_E_BASE + 0x04u))
#define GPIO_E_OSPEEDR             (*(volatile unsigned long *)(GPIO_E_BASE + 0x08u))
#define GPIO_E_PUPDR			   (*(volatile unsigned long *)(GPIO_E_BASE + 0x0Cu))
#define GPIO_E_IDR			       (*(volatile unsigned long *)(GPIO_E_BASE + 0x10u))
#define GPIO_E_ODR			       (*(volatile unsigned long *)(GPIO_E_BASE + 0x14u))
#define GPIO_E_BSRR				   (*(volatile unsigned long *)(GPIO_E_BASE + 0x18u))
#define GPIO_E_AFRL				   (*(volatile unsigned long *)(GPIO_E_BASE + 0x20u))
#define GPIO_E_AFRH			       (*(volatile unsigned long *)(GPIO_E_BASE + 0x24u))
#define GPIO_E_BRR  			   (*(volatile unsigned long *)(GPIO_E_BASE + 0x28u))
/*--------------------------------port F------------------------------------------*/
#define GPIO_F_MODER               (*(volatile unsigned long *)(GPIO_F_BASE + 0x00u))
#define GPIO_F_OTYPER			   (*(volatile unsigned long *)(GPIO_F_BASE + 0x04u))
#define GPIO_F_OSPEEDR             (*(volatile unsigned long *)(GPIO_F_BASE + 0x08u))
#define GPIO_F_PUPDR			   (*(volatile unsigned long *)(GPIO_F_BASE + 0x0Cu))
#define GPIO_F_IDR			       (*(volatile unsigned long *)(GPIO_F_BASE + 0x10u))
#define GPIO_F_ODR			       (*(volatile unsigned long *)(GPIO_F_BASE + 0x14u))
#define GPIO_F_BSRR				   (*(volatile unsigned long *)(GPIO_F_BASE + 0x18u))
#define GPIO_F_AFRL				   (*(volatile unsigned long *)(GPIO_F_BASE + 0x20u))
#define GPIO_F_AFRH			       (*(volatile unsigned long *)(GPIO_F_BASE + 0x24u))
#define GPIO_F_BRR  			   (*(volatile unsigned long *)(GPIO_F_BASE + 0x28u))

#endif

