Mục đích : xây dựng các hàm delay với thời gian chính xác bằng system timer
	delay_us => delay_ms =>delay_s
	su dung phuong phap polling
System timer (Systick)

A. Danh sánh những module liên quan:
- Clock (RCC):
	-> Tính toán giá trị clock chính xác cấp cho System Timer (Systick) HSE 8MHz(RCC_HSE_init())
	-> xem hình ảnh Clock tree
- System Timer:
	-> khởi tạo module.
	-> Viết hàm start/get_state
B. System Timer:
1. Khởi tạo system timer:
	- Disable systick
	- Lựa chọn source clock cho Systick(processer  or refence)
	- Set giá trị bằng 0 cho SYST_CVR register
2. Start timer:
	- Ghi giá trị cho thanh ghi reload
		-(SYST_RVR = (Tcounter/Tperiod)-1)
		- Tperiod = 1/(F_HSE)(8MHz)
	- Ghi giá trị bằng 0 cho current value register
	- Ghi 1 tới bit enable Systick trong thanh ghi SYST_CSR
3. Kiểm tra trạng thái của cờ tràn
	- đọc giá trị bit COUNTFLAG trong thanh ghi SYST_CSR