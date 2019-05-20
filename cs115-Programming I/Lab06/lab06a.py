'''
Program: CS 115 Lab 6a
Author: Christian Esperon
Description: This program will ask the user for a value
   and tell the user whether the value is even or odd.
'''


def main():

    N = int(input('Enter a number: '))
    while N != 1:
        if N % 2 == 1:
            N = 3 * N +1

        else:
            N= N//2

        print(N,'.' ,sep = '')



main()