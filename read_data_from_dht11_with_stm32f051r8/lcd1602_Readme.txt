Lập trình giao tiếp với LCD1602 chế độ 4 bít
Sơ đồ chân kết nối:
		#define RS	PC10
		#define E	PC11
		#define DB4	PC6
		#define DB5	PC7
		#define DB6	PC8
		#define DB7	PC9
Các hàm điều khiển lcd1602:
		void init_pin();
			=>cấp clock cho gpio Port C
			=>sét các chân kết nối với LCD là output
		void lcd_Init();
			=> hàm chứa các lệnh khởi tạo cho lcd
		void lcd_Enable();
			=> hàm tạo xung chốt dữ liệu trên chân E
		void lcd_send4bit(unsigned char data);
			=> hàm gửi 4 bít dữ liệu ra 4 chân D4->D7
		void lcd_sendCommand(unsigned char cmd);
			=> hàm gửi 1 lệnh cho lcd
		void lcd_Clear();
			=> hàm xóa màn hình
		void lcd_gotoxy(unsigned char x,unsigned char y);
			=> di chuyển con trỏ đên vị trí hàng y cột x
		void lcd_putchar(unsigned char data);
			=> hàm gửi 1 ký tự ra cho lcd
		void lcd_puts(char *str);
			=> hàm gửi 1 chuỗi cho lcd