#include"sw_delay.h"
/* Khoi tao system timer*/
void systick_init(){
	SYST_CSR = 0x00000000u;//disable systick
	SYST_CSR |= (1<<2);//chon prosesser clock
	SYST_CSR |= ~(1<<1);//cam ngat
//	SYST_CVR = 0x0u;//xoa gia tri cho thanh ghi dem trang thai
////	SYST_RVR = 0x0;
}
/*start systick*/
void start_timer(unsigned int value){
	SYST_RVR = value;
	SYST_CVR = 0x00000000u;
	SYST_CSR |= ~(1<<0);
	SYST_CSR |= (1<<0);//enable systick
}
/*doc ve trang thai cua bit 16 (co flag khi timer dem ve 0)*/
unsigned int get_state_systick(){
	unsigned int temp;
	temp = SYST_CSR & (1<<16);
	temp = temp >> 16;
	return temp;
}
/*delay us*/
void delay_us(unsigned int value){
	while(value--){
        start_timer(0x0007); /* 1 us */
        while(0 == get_state_systick());
    }
}
/*delay ms*/
void delay_ms(unsigned int value){
    while(value--){
        start_timer(0x1F3Fu); /* 1 ms */
        while(0 == get_state_systick());
    }
}
/*delay ms*/
void delay_s(unsigned int value){
	delay_ms(value*1000);
}
