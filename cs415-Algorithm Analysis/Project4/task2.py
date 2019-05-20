# Knapsack problem solved through a greedy approach

import p4functions as func
import operator

def knapsack(C, W, V):

    # Order the items by their value/weight

    value_ratio_list = []
    for i in range(len(V)):
        # [item index, value/weight, weight]
        value_ratio_list.append([i, V[i] / W[i], W[i]])

    value_ratio_list = sorted(value_ratio_list, key=operator.itemgetter(1), reverse=True)

    # Add items to our solution until we can't fit an item

    solution = []
    for n in value_ratio_list:

        # If it fits
        if C >= n[2]:
            solution.append(n[0] + 1)  # Add it to the sack (adding 1 because item labels start from 1)
            C -= n[2]  # Subtract its weight from our capacity
        # If it doesn't
        else:
            break  # Stop adding items

    # Calculate the value from the optimal solution
    optimal_value = 0
    for n in solution:
        optimal_value += V[n - 1]  # Subtracting 1 because item labels start from 1

    # Sort the values before returning
    solution.sort()
    return optimal_value, solution
