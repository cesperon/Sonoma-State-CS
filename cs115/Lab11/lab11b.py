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


def isNumber(s): # Helper function to check if it is a Number or a string
    try:
        float(s)
        return True
    except ValueError:
        return False

def find_index_of_min(L,start_index):
    """
    Parameter: a list L
    Returns: the index of the minimum element of the list
        (returns None if the list is empty)
    """

    if L == [] or start_index > (len(L)-1) :
        return None
    elif isNumber(L[0]):
        min = float('inf')
        for i in range(start_index, (len(L))):
            if L[i] < min:
                min = L[i]
                min_index = i
        return min_index
    else:
        min = 'Z'
        for i in range(start_index, (len(L))):
            if L[i] < min:
                min = L[i]
                min_index = i
        return min_index

def selection_sort(L):
    '''
    Use the selection sort algorithm to sort a list.
    Parameter: unsorted list
    Sorts the original list that was passed to it -- doesn't return anything.
    '''






    for i in range (len(L)-1):

        min_index= find_index_of_min(L,i)

        x= L[i]

        y= L[min_index]

        L[i]= L[min_index]

        L[min_index]= x


        print('Swapped elements',i,'and',min_index,'--',x,'and',y)





import sys
import math

def main():
    """ Read and print a file's contents. """

    # filename = str(input('Name of input file: '))
    # string = readfile(filename)
    # print()
    # print('The original list of cities is:')
    # for i in range(len(string)):
    # print(i, ':', string[i], sep="")
    filename = str(input('Name of input file: '))

    string = readfile(filename)


    print()
    print('The original list of cities is:')
    for i in range(len(string)):
        print(i, ':', string[i], sep="")
    sorted_list = selection_sort(string)
    print()
    print('The new list of cities is:')


    print_list(string)

main()
