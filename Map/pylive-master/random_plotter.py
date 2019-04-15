from pylive import live_plotter
import numpy as np
import serial
import theading

data = [0,0]
ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM1'
if(ser.is_open==False):
	ser.open()

x_vec = [0,0,0,0,0,0,0,0,0,0]
print(x_vec)
y_vec = [0,0,0,0,0,0,0,0,0,0]
print(y_vec)
line1 = []

def plot():
	pass
while True:
	t = Timer(plot,0)
	try:
		# data_recive = ser.read_until();
		# data = data_recive.decode('utf-8')
		# data = data[:-1]
		# data = data.split('_')
		# print(data)
		rand_val = np.random.randint(0,10)
		y_vec[-1] = rand_val
		line1 = live_plotter(x_vec,y_vec,line1)
		y_vec = np.append(y_vec[1:],0.0)
	except:
		ser.close();
		print("Not recive data from serial");
		exit();

  
