from datetime import datetime
import random
import time
import serial
from threading import*
from tkinter import*
from tkinter import ttk
def login_init():
	global app;
	app = Tk();
	app.title("Transform");
	app.geometry("400x200");
	app.resizable(height= False,width = False);
	app.protocol("WM_DELETE_WINDOW",close)
def close():
	global ser,check_trans;
	check_trans = 0;
	ser.close();
	exit();
def setup_ui():
	global port,baudrate,status,temperature,humidity,ser;

	ser = serial.Serial()
	ser.baudrate = 9600
	ser.port = 'COM2'
	ser.timeout = 1;
	if(ser.is_open==False):
		ser.open()
	# print(ser.is_open)
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

	lbl_port = Label(app,text = "Port: ",bg = "white",fg= "black",font=("Times",16,'bold'));
	lbl_baudrate = Label(app,text = "Baudrate:",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_status = Label(app,text = "status:",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_temp = Label(app,text = "Temperature: ",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_hum = Label(app,text = "Humidity: ",bg="white",fg = "black",font=("Times",16,'bold'));

	lbl_port.grid(row = 0,column = 0);
	lbl_baudrate.grid(row = 1,column = 0);
	lbl_status.grid(row = 2,column = 0);
	lbl_temp.grid(row = 3,column = 0);
	lbl_hum.grid(row = 4, column = 0);

	lbl_port_val = Label(app,textvariable = port,font=("Times",16,'bold'),height = 1,width = 20,fg = "#EC870E");
	lbl_baudrate_val = Label(app,textvariable = baudrate,font=("Times",16,'bold'),height = 1,width = 20,fg = "#EC870E");
	lbl_status_val = Label(app,textvariable = status,font=("Times",16,'bold'),height = 1,width = 20,fg = "#EC870E");
	lbl_temp_val = Label(app,textvariable = temperature,font=("Times",16,'bold'),height = 1,width = 20,fg = "#EC870E");
	lbl_hum_val = Label(app,textvariable = humidity,font=("Times",16,'bold'),height = 1,width = 20,fg = "#EC870E");

	lbl_port_val.grid(row = 0,column = 1);
	lbl_baudrate_val.grid(row = 1,column = 1);
	lbl_status_val.grid(row = 2,column = 1);
	lbl_temp_val.grid(row = 3,column = 1);
	lbl_hum_val.grid(row = 4,column = 1);
def random_data():
	global temperature,humidity,check_trans,ser;
	while check_trans == 1:
		temperature.set(random.randint(0,80))
		humidity.set(random.randint(0,100))
		data_trans = str(temperature.get()) +"_"+str(humidity.get())+'\n' 
		print(data_trans)
		try:
			ser.write(data_trans.encode('utf-8'))
			time.sleep(2);
		except:
			ser.close();
			exit();
			app.destroy();
if __name__ == '__main__':
	global check_trans;
	check_trans = 0;
	login_init();
	setup_ui();
	t = Timer(0, random_data);
	check_trans = 1;
	t.start();
	mainloop();