import sqlite3 as sql
from datetime import datetime
import random
import time
import serial
from threading import*
from tkinter import*
from tkinter import ttk
from PIL import ImageTk,Image
import os
import sys
from tkinter.ttk import Combobox
from tkinter import messagebox
import serial.tools.list_ports
import read_data_from_8051 as live_plot

port_select = -1;
ser = serial.Serial();
# hàm được gọi khi chọn 1 giá trị trong combobox
def callback_port(event):
	global combox,port_select;
	port_select = str(combox.get())
	print(port_select)
# Hàm khởi tạo cổng nối tiếp( tốc độ baund,port, timeout) và khởi tạo form hiển thị chính
def start():
	global port_select,t,check_recive,ser;
	if(port_select==-1):
		print("Please select")
	else:
		print("OK!!!",port_select)
		ser.port = str(port_select)
		ser.baudrate = 9600
		ser.timeout = 2
		try:
			ser.open();
			x = 1;
		except:
			x = 0;
		if(x==1):
			app.destroy();
			ui_init();
			setup_ui();
			t.start();
			check_recive = 1;
			ui.mainloop();
		else:
			print("Please choose others port!")
			messagebox.showwarning("Error", "Port is aready\nPlease choose other port")
# hàm insert dữ liệu nhiệt độ độ ẩm vào databases
def insert_data(temperature,humidity):
	path  = "database\\database_of_map.db";
	con = sql.connect(path);
	table_name = "Table_"+str(datetime.now().day) +"_"+str(datetime.now().month)+ "_" +str(datetime.now().year)
	with con:
		cur  = con.cursor();
		cmd = "CREATE TABLE IF NOT EXISTS " + table_name + '''(
			temperature INT(3) NOT NULL,
			humidity INT(3) NOT NULL,
			time CHAR(10) NOT NULL ) 
			'''
		cur.execute(cmd)
		cmd = "INSERT INTO " + table_name +" VALUES(?,?,?)";
		time_read = str(datetime.now().hour) + ":" + str(datetime.now().minute) + ":" +str(datetime.now().second)
		print("Temperature: ",temperature ,"humidity: ",humidity, " Time: ",time_read);
		cur.execute(cmd,(temperature,humidity,time_read))
	con.close();
# khởi tạo form chọn port ban đầu
def choose_port_init():
	global app;
	app = Tk();
	app.title("SELECT_PORT");
	app.geometry("400x200+420+150");
	app.resizable(height= False,width = False);
	app.protocol("WM_DELETE_WINDOW",quit)
# Cài đặt cấu hình cho form chọn port ban đầu
def choose_port_setup():
	global app,combox;
	Ports = []
	ports = serial.tools.list_ports.comports()
	for port in ports :
		Ports.append(port.device)
	print(Ports)
	lbl_select = Label(app,text = "Please select COM port!",bg = "white",fg= "black",font=("Times",16,'bold'));
	lbl_select.pack();
	lbl_select = Label(app,fg= "black",font=("Times",16,'bold'));
	lbl_select.pack();
	combox = Combobox(app, values=Ports, width=36);
	combox.set("please select COM port here");
	combox.pack()
	combox.bind("<<ComboboxSelected>>",callback_port);
	lbl_select = Label(app,fg= "black",font=("Times",16,'bold'));
	lbl_select.pack();
	btn_select = Button(app,text = "Choose",bg = "white",fg= "green",font=("Times",16,'bold'),command= start)
	btn_select.pack();
# hàm được gọi khi nhấn nút close đỏ trên màn hình
def quit():
	global check_recive;
	x = messagebox.askokcancel("Quit","Do you want to quit?");
	if(x == True):
		check_recive = 0;
		sys.exit();
		try:
			ui.destroy();
		except:
			print("khong co ui");
		try:
			app.destroy();
		except:
			print("khong co app");
		exit();
# hàm khởi tạo cho form hiển thị chính
def ui_init():
	global ui;
	ui = Tk();
	ui.title("Recive");
	ui.geometry("500x250");
	ui.resizable(height= False,width = False);
	ui.protocol("WM_DELETE_WINDOW",quit)	
# hàm được gọi khi nhấn nút vẽ đồ thị
def graph():
	global ser,check_recive,port_select;
	ser.close();
	ui.destroy();
	check_recive = 0;
	live_plot.data_init();
	live_plot.serial_init(str(port_select));
	live_plot.draw_plot();
# hàm cài đặt cấu hình cho form hiển thị chính
def setup_ui():
	global port,baudrate,status,temperature,humidity,ser,data,port_select;
	data = [0,0];
	
	#print("please check other port")

	port = StringVar();
	baudrate = StringVar();
	status = StringVar();
	temperature = IntVar();
	humidity = IntVar();


	port.set(str(ser.port));
	baudrate.set(str(ser.baudrate))
	status.set(str(ser.is_open))
	temperature.set(0);
	humidity.set(0);

	lbl_port = Label(ui,text = "Port: ",bg = "white",fg= "black",font=("Times",16,'bold'));
	lbl_baudrate = Label(ui,text = "Baudrate:",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_status = Label(ui,text = "Status:",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_temp = Label(ui,text = "Temperature: ",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_hum = Label(ui,text = "Humidity: ",bg="white",fg = "black",font=("Times",16,'bold'));

	btn_viewgraph = Button(ui,text = "Views Graph",bg="white",fg = "black",font=("Times",16,'bold'),command = graph);

	lbl_port.grid(row = 0,column = 0);
	lbl_baudrate.grid(row = 1,column = 0);
	lbl_status.grid(row = 2,column = 0);
	lbl_temp.grid(row = 3,column = 0);
	lbl_hum.grid(row = 3, column = 1);

	lbl_port_val = Label(ui,textvariable = port,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_baudrate_val = Label(ui,textvariable = baudrate,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_status_val = Label(ui,textvariable = status,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_temp_val = Label(ui,textvariable = temperature,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_hum_val = Label(ui,textvariable = humidity,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");

	progressbar_temp = ttk.Progressbar(ui,mode='determinate',orient="horizontal", length= 100,variable = temperature,maximum = 100)
	progressbar_hum = ttk.Progressbar(ui,mode='determinate',orient="horizontal", length= 100,variable = humidity,maximum = 100)
	
	lbl_port_val.grid(row = 0,column = 1);
	lbl_baudrate_val.grid(row = 1,column = 1);
	lbl_status_val.grid(row = 2,column = 1);
	lbl_temp_val.grid(row = 4,column = 0);
	lbl_hum_val.grid(row = 4,column = 1);
	progressbar_temp.grid(row = 5,column = 0)
	progressbar_hum.grid(row = 5,column = 1)
	btn_viewgraph.grid(row = 6,column = 0,columnspan=2)
# hàm đọc dữ liệu từ cổng COM và hiển thị dữ liệu lên form chính
def recive_data():
	global temperature,humidity,check_recive,ser,data;
	print("Connected!")
	while check_recive == 1:
		try:
			data_recive = ser.read_until();
			data = data_recive.decode('utf-8')
			data = data[:-1]
			data = data.split('_')
			print(data)
			temperature.set(data[0]);
			humidity.set(data[1]);
			insert_data(data[0],data[1]);
		except:
			print("Please check port connect!!")

if __name__ == '__main__':
	global check_recive,t;
	t = Timer(0,recive_data);
	check_recive = 0;
	choose_port_init();
	choose_port_setup();
	mainloop();