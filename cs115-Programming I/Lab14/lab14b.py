"""
Program: CS 115 Lab 10
Author: Christian Esperon
Description: This program will open a file and then search its contents
             using linear and binary search.
"""


def readfile(filename):
    """
    Reads the entire contents of a file into a single string using
    the read() method.

    Parameter: the name of the file to read (as a string)
    Returns: the text in the file as a large, possibly multi-line, string
    """

    infile = open(filename, "r")  # open file for reading

    # Use Python's file read function to read the file contents
    filetext = infile.read().splitlines()

    infile.close()  # close the file

    return filetext  # the text of the file, as a single string


def print_list(list_to_print):
    """
    Print the contents of a list.

    Parameter: the list to print
    Returns: nothing
    """

    for i, item in enumerate(list_to_print):
        print(i, ': ', item, sep="")


def linear_search(search_list, value_to_find):
    """
    Uses a hand-coded linear search to find the position of an item in a list

    Parameters: the list; the item to search for
    Returns: the position of the item in the list
        (or None if it is not in the list)
    """

    for i in range(len(search_list)):
        if search_list[i] == value_to_find:
            return i

def binary_search_recursive(search_list, value_to_find, start, end):
    """"
    Uses recursion as a means of performing a binary search on search_list
    """


    print('Binary searching between', start, 'and', end)

    if start > end:
        return None

    middle = ((start + end) // 2)

    if value_to_find == search_list[middle]:

        return middle

    if value_to_find > search_list[middle]:
        start = middle + 1

    if value_to_find < search_list[middle]:
        end = middle - 1


    return binary_search_recursive(search_list,value_to_find, start, end)



def binary_search(search_list, value_to_find):
    """
    Uses a binary search function to find the position of an item in a list
    Parameters: the list; the item to search for
    Returns: the position of the item in the list
             (or None if it is not in the list)
    """
    iteration = 0

    start= 0

    end = len(search_list)- 1

    return binary_search_recursive(search_list, value_to_find, start, end)

    #middle= ((start+end)//2)

    #while start <= end:
    #     middle = ((start + end) // 2)
    #
    #     iteration+=122
    #
    #
    #     if value_to_find == search_list[middle]:
    #         print('**Binary search iterations:',iteration)
    #         return middle
    #
    #
    #     if value_to_find > search_list[middle]:
    #         start = middle + 1
    #
    #     if value_to_find < search_list[middle]:
    #         end = middle - 1
    #
    # print('**Binary search iterations:', iteration)


import sys


def main():
    """ Read and print a file's contents. """

    filename = str(input('Name of input file: '))


    string = readfile(filename)

    print()
    print('The original list of cities is:')
    for i in range(len(string)):
        print(i, ':', string[i], sep="")


    print()
    print('After sorting, the new list is:')

    sorted_string= sorted(string)

    for i in range (len(sorted_string)):
        print(i, ':', sorted_string[i], sep="")

    print()

    name_city = input('Enter the name of  city: ')

    while name_city.lower() != "quit":
        #linear_position = linear_search(sorted_string, name_city)

        #print('Linear search:', linear_position, )

        binary_position = binary_search(sorted_string, name_city)


        print('The position of',name_city,'is:', binary_position)



        print()

        name_city2 = input('Enter the name of city: ')

        name_city = name_city2



main()