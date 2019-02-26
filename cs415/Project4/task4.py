import matplotlib.pyplot as plot
import p4functions as func
import time
import task1
import task2

def setPlot(title, xlabel, ylabel):
    figure = plot.figure()
    plot.legend(loc='upper left')
    plot.title(title)
    plot.xlabel(xlabel)
    plot.ylabel(ylabel)
    return figure

def task_four_plot(n, dynamic, greedy):
    figure = setPlot('Number of Items', 'n', 'CPU Time')
    ax1 = figure.add_subplot(111)
    ax1.scatter(n, dynamic, s=10, c='b', marker="s", label='Dynamic Programming')
    ax1.scatter(n, greedy, s=10, c='r', marker="o", label='Greedy Approach')
    plot.show()


# Build lists of data
data_c, data_w, data_v = [], [], []
for i in range(8):

    data_c.append(func.get_input("p0" + str(i) + "_c.txt"))
    data_w.append(func.get_input("p0" + str(i) + "_w.txt"))
    data_v.append(func.get_input("p0" + str(i) + "_v.txt"))

n = []
for x in data_v:
    n.append(len(x))

# Do the tests
dynamic_times, greedy_times = [], []
for i in range(len(n)):

    # Dynamic Programming
    starttime = time.clock()
    task1.knapsack(data_c[i][0], data_w[i], data_v[i])
    stoptime = time.clock()
    dynamic_times.append(stoptime - starttime)

    # Greedy Method
    starttime = time.clock()
    task2.knapsack(data_c[i][0], data_w[i], data_v[i])
    stoptime = time.clock()
    greedy_times.append(stoptime - starttime)

task_four_plot(n, dynamic_times, greedy_times)
