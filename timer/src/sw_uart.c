#include"sw_uart.h"
void Usart1_Init(){
	/*set mode chan Tx*/
	GPIO_setmode('A',9,2);
	GPIO_A_AFRH &= ~(0xF<<4);
	GPIO_A_AFRH |= (AF1<<4);
	/*set mode chan Rx*/
	GPIO_setmode('A',10,2);
	GPIO_A_AFRH &= ~(0xF<<8);
	GPIO_A_AFRH |= (AF1<<8);
/*khoi tao module uart1*/
	//disable USART1
	USART1_CR1 &= ~(1<<0);
	//che do 1start bit ,8 dat n stop bit,none parity
	USART1_CR1 &= ~(1<<28) | ~(1<<12) |~(1<<10);
	//che do 1 bit stop
	USART1_CR2 &= ~(0x3<<12); 
	//che do oversam 16
	USART1_CR1 &= ~(1<<15);
	//toc do baund 9600
	USART1_BRR = 0x314u;	
	//enable ngoai vi USART1
	USART1_CR1 |= (1<<0);
	//enable TX
	USART1_CR1 |= (1<<3);
	//enable RX
	USART1_CR1 |= (1<<2);
}
char Usart1_sendbyte(unsigned char data){
	unsigned int temp_reg;
    char state = 0; 
    /* kiểm tra xem TDR sẵn sàng nhận dữ liệu mới chưa */
    temp_reg = USART1_ISR & (1<<7);
    if (0 != temp_reg){
       USART1_TDR = (unsigned int)data;
    }
    else{
        state = -1;
    }
    return state;
}
char Usart1_send_string(char *str_data){    
    char state = 0;
    while(*str_data)
    {
        if (0 == Usart1_sendbyte(*str_data))
        {
            str_data++;
        }
    }
    return state;
}
