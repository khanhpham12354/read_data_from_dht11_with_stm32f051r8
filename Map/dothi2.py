from datetime import datetime
from matplotlib import pyplot
from matplotlib.animation import FuncAnimation
from random import randrange
count = 0
def db_count():
    ### Connect to db and run query ...
    count = randrange(19, 40)
    return count
x_data, y_data = [], []

figure = pyplot.figure()
count = db_count
line, = pyplot.plot_date(x_data, y_data, '-',label = "temp")

def update(frame):
    x_data.append(datetime.now())
    count = db_count()
    y_data.append(count)
    line.set_data(x_data, y_data)
    line.set_label(count)
    pyplot.legend(bbox_to_anchor=(1.05, 0.05))
    figure.gca().relim()
    figure.gca().autoscale_view()
    return line,

animation = FuncAnimation(figure, update, interval=200)
pyplot.gcf().autofmt_xdate()
pyplot.xticks(rotation=45)
pyplot.show()