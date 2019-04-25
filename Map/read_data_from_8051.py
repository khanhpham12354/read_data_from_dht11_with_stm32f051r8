import serial
import matplotlib.pyplot as plt
from drawnow import *
from datetime import datetime
import sys
import sqlite3 as sql



temp = []
hum = []
data = [0,0]
times = []

plt.ion()

cnt = 0


maxTemp = 0;
maxHum = 0;

ser = serial.Serial();
# hàm khởi tạo cổng nối tiếp
def serial_init(port_select):
	ser.port = str(port_select)
	ser.baudrate = 9600
	ser.timeout = 2
	ser.open();
# hàm insert dữ liệu vào cơ sở sữ liệu
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
# hàm cấu hình cho đồ thị
def plotValues():

    plt.title('Dữ Liệu Từ Trung tâm Khí Tượng Thủy Văn\nTam Mao')
    plt.grid(True)

    plt.xlabel('Times')

    plt.ylabel('Temperature',color='r')
    plt.plot(times,temp, 'r', label='Temperature\nMax:'+str(maxTemp))
    plt.ylim(-50,70)
    plt.legend(loc='upper left')

    plt2 = plt.twinx()

    plt2.plot(times,hum, 'g', label='Humidity\nMax:'+str(maxHum))

    plt2.set_ylabel('Humidity', color='g')
    plt2.legend(loc='upper right')
    plt.ylim(0,100)
# hàm khởi tạo dữ liệu ban đầu
def data_init():
	for i in range(0,10):
	    temp.append(0)
	    hum.append(0);
	    times.append(0)
# hàm vẽ đồ thị thời gian thực
def draw_plot():
	while True:
		try:
			data_recive = ser.read_until();
			data = data_recive.decode('utf-8')
			print(data)
			data = data[:-1]
			data = data.split('_')
			print(data)
			TempInInt = int(data[0])
			HumInInt = int(data[1])
			insert_data(TempInInt,HumInInt)
			time_read = str(datetime.now().hour) + ":" + str(datetime.now().minute) + ":" +str(datetime.now().second)
			times.append(time_read)
			times.pop(0)
			temp.append(TempInInt)
			temp.pop(0)
			maxTemp = max(temp)
			hum.append(HumInInt)
			hum.pop(0)
			maxHum = max(hum)
			drawnow(plotValues,stop_on_close=True)
		except:
			ser.close();
			print("Bye Bye!!!");
			sys.exit();
