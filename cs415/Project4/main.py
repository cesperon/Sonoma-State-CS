# Project 4
# CS-415 Fall 2018
# Brandon Adamson-Rakidzich
# Christian Esperon

import p4functions as func
import time
import task1
import task2

# Set to true to use test values, located in KnapsackTestData in the same directory
test_values = False

if test_values is True:
    data_c = func.get_input("p07_c.txt")
    data_w = func.get_input("p07_w.txt")
    data_v = func.get_input("p07_v.txt")
else:
    data_c = func.get_input(input("Enter file containing the capacity: "))
    data_w = func.get_input(input("Enter file containing the weights: "))
    data_v = func.get_input(input("Enter file containing the values: "))
    print("")


print("Knapsack capacity = ", data_c[0], ". Total number of items = ", len(data_v), sep='')
print("")

# Task 1
starttime = time.clock()
knapsack_dynamic_val, knapsack_dynamic_items = task1.knapsack(data_c[0], data_w, data_v)
stoptime = time.clock()
print("Dynamic Programming Optimal Value: ", knapsack_dynamic_val, sep='')
print("Dynamic Programming Optimal Subset: ", knapsack_dynamic_items, sep='')
print("Dynamic Programming Time Taken: ", stoptime-starttime, sep='')

print("")

# Task 2
starttime = time.clock()
greedy_val, greedy_items = task2.knapsack(data_c[0], data_w, data_v)
stoptime = time.clock()
print("Greedy Approach Optimal Value: ", greedy_val, sep='')
print("Greedy Approach Optimal Subset: ", greedy_items, sep='')
print("Greedy Approach Time Taken: ", stoptime-starttime, sep='')

