GPIO:
Các bước khởi tạo cho GPIO:
	=> cấp clock cho port cần dùng(RCC_EnClkIOport(port);)
	=> chọn mode hoạt động cho pin(void GPIO_setmode)
	=> muốn cho chân đó lên mức 1: void GPIO_setbit()
						xuống mức 0: void GPIO_resetbit()
	=> xuất dữ liệu ra cả port:	void GPIO_ODRport(unsigned char port,unsigned char data);