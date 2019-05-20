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

def find_index_of_min(L):
    """
    Parameter: a list L
    Returns: the index of the minimum element of the list
        (returns None if the list is empty)
    """


    min = float('inf')
    for i in range (len(L)):
        if L[i] < min:
            min = i
        return min


















import sys

import math
def main():
    """ Read and print a file's contents. """

    #filename = str(input('Name of input file: '))


    #string = readfile(filename)

    #print()
    #print('The original list of cities is:')
    #for i in range(len(string)):
        #print(i, ':', string[i], sep="")

    print(find_index_of_min([]))
    print(find_index_of_min([3, 2, 1, 0]))
    




main()
