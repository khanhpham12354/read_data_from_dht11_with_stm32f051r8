#include"sw_gpio.h"

void GPIO_setpull_up(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			GPIO_A_PUPDR &= ~(0x03<<(2*pin));
			GPIO_A_PUPDR |= (0x01<<(2*pin));
			break;
		case 'B':
			GPIO_B_PUPDR &= ~(0x03<<(2*pin));
			GPIO_B_PUPDR |= (0x01<<(2*pin));
			break;
		case 'C':
			GPIO_C_PUPDR &= ~(0x03<<(2*pin));
			GPIO_C_PUPDR |= (0x01<<(2*pin));
			break;
		case 'D':
			GPIO_D_PUPDR &= ~(0x03<<(2*pin));
			GPIO_D_PUPDR |= (0x01<<(2*pin));
			break;
		case 'E':
			GPIO_E_PUPDR &= ~(0x03<<(2*pin));
			GPIO_E_PUPDR |= (0x01<<(2*pin));
			break;
		case 'F':
			GPIO_F_PUPDR &= ~(0x03<<(2*pin));
			GPIO_F_PUPDR |= (0x01<<(2*pin));
			break;
	}
}
void GPIO_setpull_down(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			GPIO_A_PUPDR &= ~(0x03<<(2*pin));
			GPIO_A_PUPDR |= (0x02<<(2*pin));
			break;
		case 'B':
			GPIO_B_PUPDR &= ~(0x03<<(2*pin));
			GPIO_B_PUPDR |= (0x02<<(2*pin));
			break;
		case 'C':
			GPIO_C_PUPDR &= ~(0x03<<(2*pin));
			GPIO_C_PUPDR |= (0x02<<(2*pin));
			break;
		case 'D':
			GPIO_D_PUPDR &= ~(0x03<<(2*pin));
			GPIO_D_PUPDR |= (0x02<<(2*pin));
			break;
		case 'E':
			GPIO_E_PUPDR &= ~(0x03<<(2*pin));
			GPIO_E_PUPDR |= (0x02<<(2*pin));
			break;
		case 'F':
			GPIO_F_PUPDR &= ~(0x03<<(2*pin));
			GPIO_F_PUPDR |= (0x02<<(2*pin));
			break;
	}
}
_Bool GPIO_readpin(unsigned char port,unsigned char pin){
	_Bool pin_state = 0;
	switch(port){
		case 'A':
			pin_state = GPIO_A_IDR & (1<<pin);
			break;
		case 'B':
			pin_state = GPIO_B_IDR & (1<<pin);
			break;
		case 'C':
			pin_state = GPIO_C_IDR & (1<<pin);
			break;
		case 'D':
			pin_state = GPIO_D_IDR & (1<<pin);
			break;
		case 'E':
			pin_state = GPIO_E_IDR & (1<<pin);
			break;
		case 'F':
			pin_state = GPIO_F_IDR & (1<<pin);
			break;
	}
	return pin_state;
}
void GPIO_setmode(unsigned char port,unsigned char pin,unsigned char mode){
	switch(port){
		case 'A':
		{
			switch(mode){
				case 0:
					GPIO_A_MODER &= ~(0x03<<(2*pin));
					GPIO_A_MODER |= (INPUT<<(2*pin));
					break;
				case 1:
					GPIO_A_MODER &= ~(0x03<<(2*pin));
					GPIO_A_MODER |= (OUTPUT<<(2*pin));
					break;
				case 2:
					GPIO_A_MODER &= ~(0x03<<(2*pin));
					GPIO_A_MODER |= (ALT<<(2*pin));
					break;
				case 3:
					GPIO_A_MODER &= ~(0x03<<(2*pin));
					GPIO_A_MODER |= (ANALOG<<(2*pin));
					break;
			}
			break;
		}
		case 'B':
		{
			switch(mode){
				case 0:
					GPIO_B_MODER &= ~(0x03<<(2*pin));
					GPIO_B_MODER |= (INPUT<<(2*pin));
					break;
				case 1:
					GPIO_B_MODER &= ~(0x03<<(2*pin));
					GPIO_B_MODER |= (OUTPUT<<(2*pin));
					break;
				case 2:
					GPIO_B_MODER &= ~(0x03<<(2*pin));
					GPIO_B_MODER |= (ALT<<(2*pin));
					break;
				case 3:
					GPIO_B_MODER &= ~(0x03<<(2*pin));
					GPIO_B_MODER |= (ANALOG<<(2*pin));
					break;
			}
			break;
		}
		case 'C':
		{
			switch(mode){
				case 0:
					GPIO_C_MODER &= ~(0x03<<(2*pin));
					GPIO_C_MODER |= (INPUT<<(2*pin));
					break;
				case 1:
					GPIO_C_MODER &= ~(0x03<<(2*pin));
					GPIO_C_MODER |= (OUTPUT<<(2*pin));
					break;
				case 2:
					GPIO_C_MODER &= ~(0x03<<(2*pin));
					GPIO_C_MODER |= (ALT<<(2*pin));
					break;
				case 3:
					GPIO_C_MODER &= ~(0x03<<(2*pin));
					GPIO_C_MODER |= (ANALOG<<(2*pin));
					break;
			}
			break;
		}
		case 'D':
		{
			switch(mode){
				case 0:
					GPIO_D_MODER &= ~(0x03<<(2*pin));
					GPIO_D_MODER |= (INPUT<<(2*pin));
					break;
				case 1:
					GPIO_D_MODER &= ~(0x03<<(2*pin));
					GPIO_D_MODER |= (OUTPUT<<(2*pin));
					break;
				case 2:
					GPIO_D_MODER &= ~(0x03<<(2*pin));
					GPIO_D_MODER |= (ALT<<(2*pin));
					break;
				case 3:
					GPIO_D_MODER &= ~(0x03<<(2*pin));
					GPIO_D_MODER |= (ANALOG<<(2*pin));
					break;
			}
			break;
		}
		case 'E':
		{
			switch(mode){
				case 0:
					GPIO_E_MODER &= ~(0x03<<(2*pin));
					GPIO_E_MODER |= (INPUT<<(2*pin));
					break;
				case 1:
					GPIO_E_MODER &= ~(0x03<<(2*pin));
					GPIO_E_MODER |= (OUTPUT<<(2*pin));
					break;
				case 2:
					GPIO_E_MODER &= ~(0x03<<(2*pin));
					GPIO_E_MODER |= (ALT<<(2*pin));
					break;
				case 3:
					GPIO_E_MODER &= ~(0x03<<(2*pin));
					GPIO_E_MODER |= (ANALOG<<(2*pin));
					break;
			}
			break;
		}
		case 'F':
		{
			switch(mode){
				case 0:
					GPIO_F_MODER &= ~(0x03<<(2*pin));
					GPIO_F_MODER |= (INPUT<<(2*pin));
					break;
				case 1:
					GPIO_F_MODER &= ~(0x03<<(2*pin));
					GPIO_F_MODER |= (OUTPUT<<(2*pin));
					break;
				case 2:
					GPIO_F_MODER &= ~(0x03<<(2*pin));
					GPIO_F_MODER |= (ALT<<(2*pin));
					break;
				case 3:
					GPIO_F_MODER &= ~(0x03<<(2*pin));
					GPIO_F_MODER |= (ANALOG<<(2*pin));
					break;
			}
			break;
		}
	}
}
void GPIO_ODRport(unsigned char port,unsigned char data){
	switch(port){
		case 'A':
			GPIO_A_ODR |= data;
			break;
		case 'B':
			GPIO_B_ODR |= data;
			break;
		case 'C':
			GPIO_C_ODR |= data;
			break;
		case 'D':
			GPIO_D_ODR |= data;
			break;
		case 'E':
			GPIO_E_ODR |= data;
			break;
		case 'F':
			GPIO_F_ODR |= data;
			break;
	}
}
void GPIO_setbit(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			GPIO_A_BSRR |= (1<<pin);
			break;
		case 'B':
			GPIO_B_BSRR |= (1<<pin);
			break;
		case 'C':
			GPIO_C_BSRR |= (1<<pin);
			break;
		case 'D':
			GPIO_D_BSRR |= (1<<pin);
			break;
		case 'E':
			GPIO_E_BSRR |= (1<<pin);
			break;
		case 'F':
			GPIO_F_BSRR |= (1<<pin);
			break;
	}
}
void GPIO_resetbit(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
			GPIO_A_BSRR |= (1<<(pin+16));
			break;
		case 'B':
			GPIO_B_BSRR |= (1<<(pin+16));
			break;
		case 'C':
			GPIO_C_BSRR |= (1<<(pin+16));
			break;
		case 'D':
			GPIO_D_BSRR |= (1<<(pin+16));
			break;
		case 'E':
			GPIO_E_BSRR |= (1<<(pin+16));
			break;
		case 'F':
			GPIO_F_BSRR |= (1<<(pin+16));
			break;
	}
}


