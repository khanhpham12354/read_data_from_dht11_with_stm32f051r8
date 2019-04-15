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
def login_init():
	global app;
	app = Tk();
	app.title("Recive");
	app.geometry("500x250");
	app.resizable(height= False,width = False);
	app.protocol("WM_DELETE_WINDOW",close)
def close():
	global ser,check_recive;
	check_recive = 0;
	ser.close();
	exit();
def graph():
	print("OK")
	os.system('python read_data_from_8051.py')
def setup_ui():
	global port,baudrate,status,temperature,humidity,ser,data;
	data = [0,0];
	ser = serial.Serial()
	ser.baudrate = 9600
	ser.port = 'COM3'
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
	lbl_status = Label(app,text = "Status:",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_temp = Label(app,text = "Temperature: ",bg="white",fg = "black",font=("Times",16,'bold'));
	lbl_hum = Label(app,text = "Humidity: ",bg="white",fg = "black",font=("Times",16,'bold'));

	btn_viewgraph = Button(app,text = "Views Graph",bg="white",fg = "black",font=("Times",16,'bold'),command = graph);

	lbl_port.grid(row = 0,column = 0);
	lbl_baudrate.grid(row = 1,column = 0);
	lbl_status.grid(row = 2,column = 0);
	lbl_temp.grid(row = 3,column = 0);
	lbl_hum.grid(row = 3, column = 1);

	lbl_port_val = Label(app,textvariable = port,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_baudrate_val = Label(app,textvariable = baudrate,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_status_val = Label(app,textvariable = status,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_temp_val = Label(app,textvariable = temperature,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");
	lbl_hum_val = Label(app,textvariable = humidity,font=("Times",16,'bold'),height = 1,width = 20,fg = "green");

	progressbar_temp = ttk.Progressbar(app,mode='determinate',orient="horizontal", length= 100,variable = temperature,maximum = 100)
	progressbar_hum = ttk.Progressbar(app,mode='determinate',orient="horizontal", length= 100,variable = humidity,maximum = 100)
	
	lbl_port_val.grid(row = 0,column = 1);
	lbl_baudrate_val.grid(row = 1,column = 1);
	lbl_status_val.grid(row = 2,column = 1);
	lbl_temp_val.grid(row = 4,column = 0);
	lbl_hum_val.grid(row = 4,column = 1);
	progressbar_temp.grid(row = 5,column = 0)
	progressbar_hum.grid(row = 5,column = 1)
	btn_viewgraph.grid(row = 6,column = 0,columnspan=2)
def recive_data():
	global temperature,humidity,check_recive,ser,data;
	try:
		while check_recive == 1:
			data_recive = ser.read_until();
			data = data_recive.decode('utf-8')
			data = data[:-1]
			data = data.split('_')
			print(data)
			temperature.set(data[0]);
			humidity.set(data[1]);
			insert_data(data[0],data[1]);
			# time.sleep(2);
	except:
		ser.close();
		print("Bye Bye!!")
		# exit();
if __name__ == '__main__':
	global check_recive;
	check_recive = 0;
	login_init();
	setup_ui();
	t = Timer(0, recive_data);
	check_recive = 1;
	t.start();
	mainloop();