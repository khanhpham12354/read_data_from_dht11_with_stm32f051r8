USART (Universal synchronous asynchronous receiver transmitter)

A. Danh sánh nh?ng module liên quan:
- Clock (RCC):
	-> Tính toán giá trị clock cấp cho USART1(8 MHz)
	-> Enable clock gate cho UART module
- GPIO:
	-> Khởi tạo mode cho các chân Tx/Rx
- USART:
	-> khởi tạo module.
	-> sử dụng ngắt để truyền nhận dữ liệu
- NVIC:
	-> khởi tạo và cho phép ngắt của USART1
	-> interrupt handler

B. USART:
1. Khởi tạo:
- Disable USART module -> USART_CR1[UE] = 0;
- Data = 8 bits -> USART_CR1[M1:M0]
- Parity = none -> USART_CR1[PCE]
- Stop = 1 bit  -> USART_CR2[STOP]
- Baudrate = 9600 bps -> thiết lâp oversample1 USART_CR1[OVER8] = 16 bits
- Ghi he so chia vao thanh ghi USART[BRR]
- Enable USART module -> USART_CR1[UE] = 1;
- Enable Tx -> USART_CR1[TE]
- Enable Rx -> USART_CR1[RE]

2. Quá trình truyền dữ liệu:
- Cần kiểm tra cờ USART_ISR[TXE]
	-> Nếu USART_ISR[TXE] = 1 -> tiến hành ghi dữ liệu vào USART_TDR = <data> (lưu ý là ghi 1 byte dữ liệu)
	-> N?u USART_ISR[TXE] = 0 -> không ghi dữ liệu vào USART_TDR
- Truyền dc dữ liệu

3. Quá trình nhận dữ liệu:
- Cần kiểm tra cờ USART_ISR[RXNE]
- Nếu USART_ISR[RXNE] = 1 -> tiến hành đọc dữ liệu trên thanh ghi USART_RDR[8:0]
- Xóa cờ ngắt USART_ISR[RXNE] bằng việc đọc dữ liệu trên USART_RDR hoặc ghi 1 tại bít USART_RQR[RXFRQ]
