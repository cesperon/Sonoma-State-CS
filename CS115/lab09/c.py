def rowSum(matrix, row_index):
    sum = 0
    for i in range(len(matrix)):
        sum = matrix[i][row_index] + sum

    return sum


def getSum(list):

    l=[]

    for i in range (len(list)):
        for j in range (list[i]):
            sum_row= rowSum(list, j)
            l.append(sum_row)

    return l

def main():

    list1 = ([1,2,3],[1,1,1],[2,2,2])
    sumlists= getSum(list1)

    print(sumlists)


main()