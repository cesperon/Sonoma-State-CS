"""
Program: CS 115 Lab 9a
Author: Christian Esperon
Description: This program will create a magic square
   whose size is specified by the user.
"""


def create_list(rows, cols):
    """
    Creates a two-dimensional array.

    Parameters: the numbers of rows and columns

    Returns: a 2D array with all values set to zero
    """

    two_d = []  # create an empty list
    for i in range(rows):
        two_d.append([])  # append an empty list to two_d
        for j in range(cols):
            two_d[i].append(0)  # two_d[i] is the empty list that we just created.
            # here, we are adding elements to it.
    return two_d


def rjust_by_n(number, n):
    """
    Return a string of length "n" with number right-justified in it.

    Parameters:
    number: an value with n or fewer digits
    n: a positive integer value

    Returns: a string of length n with a number right-justified in it.
    """
    return str(number).rjust(n)


def print_list(numbers):
    """
    Print a 1D list of numbers, where each number is right-justified
    """
    for i in range(len(numbers)):
        print(rjust_by_n(numbers[i], 4), end='')
    print()


def print_2d_list(two_d_list):
    """
    Print a 2-dimensional list
    """
    for i in range(len(two_d_list)):
        x = print_list(two_d_list[i])

    return x


def build_magic_square(square):
    """
    Create a magic square in "square"

    Parameter:
    square: a two dimensional array whose number of rows and columns are equal
            and len(square) is an odd number.

    Modifies "square" but doesn't return anything.
    """
    magic_value = 1
    square_size = len(square)
    row = 0
    col = square_size // 2
    square_size_squared = square_size * square_size
    while magic_value <= square_size_squared:
        square[row][col] = magic_value
        row -= 1
        col += 1
        if row < 0 and col > square_size - 1:
            row += 2
            col -= 1
        elif row < 0:
            row = square_size - 1
        elif col > square_size - 1:
            col = 0
        elif square[row][col] != 0:
            row += 2
            col -= 1

        magic_value += 1


def sum_row_values(matrix, row_number):
    """
    Sums the values of all entries in the row given by "row_number"

    Parameters:
    matrix: a two dimensional (square) list
    row_number: an integer value in the range 0 and len(matrix)-1

    Returns: the sum of all values of the row indicated by "row_number"
    """

    sum = 0
    for i in range(row_number):
        list_i = matrix[i]
        num_columns = len(list_i)
        for j in range(num_columns):
            sum += list_i[j]

        return sum


def sum_col_values(matrix, col_number):
    """
    Sums the values of all entries in the column given by "col_number"

    matrix: a two dimensional (square) array
    col_number: an integer value in the range 0 and len(matrix)-1

    Returns the sum of all values in the column indicated by "col_number"
    """

    sum = 0
    for i in range(col_number):
        list_i = matrix[i]
        for j in range(len(list_i)):
            sum += matrix[j][i]

        return sum


def sum_top_left_bottom_right_diagonal(matrix):
    """
    Calculates the sum of the values at matrix[0][0], matrix[1][1], etc.

    matrix: a two dimensional (square) matrix
    return value: the sum of values of the top-left to bottom-right
                  diagonal
    """

    sum = 0
    for i in range(len(matrix)):
        sum += matrix[i][i]

    return sum


def sum_top_right_bottom_left_diagonal(matrix):
    """
    Calculates the sum of the values at matrix[0][len(matrix)-1], matrix[1][len(matrix)-2], etc.

    matrix: a two dimensional (square) matrix
    return value: the sum of values of the top-right to bottom-left
                  diagonal
    """

    sum = 0
    for i in range(len(matrix)):
        sum += matrix[i][(len(matrix)) - 1]

    return sum


def is_magic_square(matrix):
    """
    returns True if the two dimensional array that "matrix" points to is a
    magic square. Otherwise, it returns False.

    matrix: a two dimensional (square) array.
    return value: True or False.
    """

    # calculate the sum of the values of the top-left to
    # bottom-right diagonal. Call it tlbr_sum.
    tlbr_sum = sum_top_left_bottom_right_diagonal(matrix)

    # calculate the sum of the values of the top-right to
    # bottom-left diagonal. Call it trbl_sum.
    trbl_sum = sum_top_right_bottom_left_diagonal(matrix)

    # if tlbr_sum is not equal to trbl_sum, return False. Otherwise,
    # proceed.
    if tlbr_sum != trbl_sum:
        return False

    # calculate the sum of each row of the matrix and compare it
    # with tlbr_sum. If the two sums are not equal, return False.
    # Otherwise, proceed.
    for i in range(len(matrix)):
        sum_of_each_row = sum_row_values(matrix, len(matrix))
        if sum_of_each_row != tlbr_sum:
            return False

    # calculate the sum of each column of the matrix and compare it
    # with tlbr_sum. If the two sums are not equal, return False.
    # Otherwise, proceed.
    for i in range(len(matrix)):
        sum_of_each_column = sum_col_values(matrix, len(matrix))
        if sum_of_each_column != tlbr_sum:
            return False

    return True



    # return True.


def read_magic_square(filename):
    """
    Read values from a file into a 2D list

    Parameter:
    filename: the name of the file

    Returns a 2D list of integer values read.
    """

    infile = open(filename, "rt")
    square = []  # start with an empty list

    for line in infile:  # read text from file
        row = []
        numbers = line.split()

        # Loop through the list of numbers.
        # Append each number to the row.
        for num in numbers:
            row.append(int(num))

        if len(row) > 0:  # Don't count blank lines
            square.append(row)  # Append the row to the 2D list

    return square


import sys


def main():
    square_size = int(input('Enter an odd integer to build a magic square:'))  # Your code goes here

    if square_size % 2 == 0:
        print(square_size, 'is not an odd integer. Terminating...')

        sys.exit()

    elif square_size % 2 != 0:
        print()
        matrix = create_list(square_size, square_size)
        build_magic_square(matrix)
        print_2d_list(matrix)

        for i in range(len(matrix)):
            sum_of_row = sum_row_values(matrix, len(matrix))
            print('The sum of values in row', i, 'is', sum_of_row)

        for i in range(len(matrix)):
            sum_of_col = sum_col_values(matrix, len(matrix))
            print('The sum of values in column', i, 'is', sum_of_col)

        sum_diagonal_top_left = sum_top_left_bottom_right_diagonal(matrix)
        print('The sum of values in diagonal is', sum_diagonal_top_left)

        sum_diagonal_top_right = sum_top_right_bottom_left_diagonal(matrix)
        print('The sum of values in diagonal is', sum_diagonal_top_right)

        if is_magic_square(matrix) == True:
            print('the above square is a magic square')

        elif is_magic_square(matrix) == False:
            print('the above sqaure is NOT a magic square')

        file_name = input('Enter the name of a file containing a matrix of number:')

        matrix2 = read_magic_square(file_name)
        print()

        print_2d_list(matrix2)

        if is_magic_square(matrix2) == True:
            print('the above square is a magic square')

        elif is_magic_square(matrix2) == False:
            print('the above sqaure is NOT a magic square')


main()
