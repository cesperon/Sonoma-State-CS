# Knapsack problem solved through dynamic programming

import p4functions as func


def knapsack(C, W, V):

    # Create our table and initialize all its values to 0
    # rows = # of items (len(V))
    # columns = capacity (C)
    table = []
    func.build_table(C, V, table)

    for i in range(len(V) + 1):
        for j in range(C + 1):

            # Value obtainable when taking no items or having 0 capacity
            if i == 0 or j == 0:
                table[i][j] = 0  # No items means no value

            # Value obtainable at capacity j
            elif W[i - 1] <= j:  # If we have j or more room left in our knapsack
                table[i][j] = max(
                    V[i - 1] + table[i - 1][j - W[i - 1]],  # Value obtainable if we take this item
                    table[i - 1][j])  # Value obtainable if we don't take this item

            else:  # If we don't have j or more room left in our knapsack
                table[i][j] = table[i - 1][j]  # Don't take the item

    return table[len(table) - 1][len(table[0]) - 1], knapsack_solution(table, W)

def knapsack_solution(table, W):

    best_set = []

    # Start considering the last item
    i = len(table) - 1

    # Start considering max capacity
    c = len(table[0]) - 1

    while c != 0 and i != 0:

        if table[i][c] > table[i-1][c]:  # This item is part of our solution
            best_set.append(i)  # Add it to our sack
            c -= W[i - 1]  # Subtract the weight
            i -= 1  # Move to the next item

        else:  # This item isn't necessarily part of our solution
            i -= 1  # Move to the next item

    # Reverse to return in ascending order
    best_set.reverse()
    return best_set
