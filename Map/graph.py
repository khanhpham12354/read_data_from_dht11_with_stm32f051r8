import numpy as np
import matplotlib.pyplot as plt
import sqlite3 as sql
import time
from datetime import datetime

def read_data():
	global list_time,list_temp,list_hum;
	list_time = [];
	list_temp = [];
	list_hum = [];
	path  = "database\\database_of_map.db";
	con = sql.connect(path);
	table_name = "Table_"+"28"+"_"+str(datetime.now().month)+ "_" +str(datetime.now().year)
	with con:
		cur  = con.cursor();
		cur.execute("SELECT* FROM "+ table_name);
		data = cur.fetchall();
		print(data)
		# print(data[0][2])
	con.close();
	for i in range(0,len(data)):
		list_time.append(data[i][2]);
		list_temp.append(data[i][0]); 
		list_hum.append(data[i][1]);
	# print(list_time)
	# print(list_temp)
	# print(list_hum)

# print(read_data())
plt.axis([-10,7,-0,10])
plt.xticks(rotation=45)
for i in range(10):
	y = np.random.randint(20,100)
	print(y)
	plt.plot(i,y,'r');
	plt.pause(0.05)
plt.show();