"""
Program: CS 115 Lab 6c
Author: Christian Esperon
Description: This program will read a positive integer and
 express it as the sum of powers of 2.
"""


def main():

    i_num= int(input('Enter a number: '  ))# Read user's input and store it in a variable called i_num.
    for i in range(i_num):# Outer loop:
        while i_num > 0:# while i_num is larger than zero:
            n=0# Initialize n and two_to_n.
            two_to_n= 2**n
            while two_to_n < i_num:  # while two_to_n is less than i_num:
                n += 1  # add 1 to n

                two_to_n = two_to_n * 2  # two_to_n =  multiply two_to_n by 2

            if two_to_n > i_num:  # if two_to_n is greater than i_num:
                n -= 1  # subtract 1 from n
                two_to_n = two_to_n / 2

            if 2 ** n == two_to_n:
                print('2**', n, sep='', end='')

            if 2 ** n > 2:
                print(' + ' , end= '')

            i_num= i_num- two_to_n



                # Do all the stuff you were doing before to find n and two_to_n.
        # Remember that two_to_n is the largest power of 2 less than i_num.








main()