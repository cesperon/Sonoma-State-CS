"""
Program: CS 115 Lab 7a
Author: Christian Esperon
Description: This program finds $1.00 words.
"""


def main():

    total = 0
    s= input('Enter a word:')# Ask the user for a word, and save the word to a variable.
    s = s.lower()# Convert the user's word to lowercase
    while s.lower() != 'quit': # As long as the user's word is not 'quit'...
        for i in range (len(s)):
            total+= (ord(s[i])-96)
        if total == 100 :
            print('Your word is worth ' "${0:.2f}.".format(total/100))
            print('Congratulations!')
        else:
            print ('Your word is worth '"$0.{0:.0f}.".format(total))# Echo their word back to them


        n=input('Enter a word:')
        n = n.lower()# Get a new word from them, convert it to lowercase,
        s = n# and save it to the same variable.
        total=0

main()
