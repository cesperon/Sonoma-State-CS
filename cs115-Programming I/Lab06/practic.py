"""
Program: CS 115 Lab 6b
Author: Your name
Description: This program will read a positive integer and
 find the largest power of two that is less than or equal to it.
"""


def main():


    i_num= int(input('Enter a number:'))# Read user's input and store it in a variable called i_num.
    n = 0 # Initialize a variable n to serve as the exponent.
    two_to_n = 2**n # Initialize a variable two_to_n to hold the value of 2**n
    for i in range(i_num):
        while two_to_n < i_num:# while two_to_n is less than i_num:
            n+=1 # add 1 to n

            two_to_n = two_to_n * 2#two_to_n =  multiply two_to_n by 2

        if two_to_n  > i_num:# if two_to_n is greater than i_num:
            n-=1# subtract 1 from n
            two_to_n= two_to_n/2

        if 2**n == two_to_n:
            two_to_n = print('2**',n, sep='')

        i_num= i_num - two_to_n




# divide two_to_n by 2

# Print the result


main()