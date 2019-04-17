Clock là trái tim của VDK(fmax STM32f051r8=48MHz):
STM32 có 2 nguồn clock chính:
	=>HSI (thạch anh nội(8Mhz))
	=>HSE (thạch anh hàn ngoài mạch) ở đây cũng nối thạch anh 8Mhz
	=>khi muốn có tần số cao hơn cần đến bộ nhân xung PLL
mặc định khi khởi động stm32f051 chạy với thạch anh nội 8MHz(clock hệ thống SYSCLK)
muốn thay đổi cần tác động đến 2 bít [1 0] cua thanh ghi RCC_CFGR để chọn 1 trong 3 nguồn
làm SYSCLK.
Các bước để chọn HSE làm SYSCLK:
	=> Khởi tạo ban đầu:
		=> Cho phép ngắt RCC
		=> sét mức ưu tiên
		=> khởi tạo ngắt kiểm tra bộ HSE hoạt động ổn định(RCC_CIR[11])
		=> bật HSE(RCC_CR[16])
		=> bật CSSON để bảo vệ clock(bộ tìm kiếm xung nhịp chỉ hoạt động khi HSE sẵn sàng)(RCC_CR[19])
		=> bỏ dao động này được bỏ qua để đợi khi nào nó ổn định RCC_CR[18](ổn định nó sẽ tạo ra ngắt)
	=> Trong hàm ngắt:
		=> Kiểm tra bít số 3 của RCC_CIR:
		=> nếu bít đó != bộ HSE đã hoạt động ổn định
		=> xóa cờ ngắt RCC_CIR[19]
		=> sét bộ HSE làm SYSCLK RCC_CFGR[1:0]
		=> xóa ngắt toàn cục __asm("cpsid i");
		