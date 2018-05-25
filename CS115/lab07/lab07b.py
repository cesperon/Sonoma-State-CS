"""
Program: CS 115 Lab 7b
Author: Christian Esperon
Description: Computes the average word length of the user's text.
"""


def main():
    total = 0
    s= input('Enter some text: ')
    l=s.split()
    v = len(l)
    e=0
    total_words= 0
    count1=0
    if s == '':
        print('You did not enter any words.')
    else:
        while len(s)!= 0:
            for i in range(len(s)):
                if s[i] == ' ':
                    e+=1

                total+=1
            total_words+=v
            count=(total-e)
            count1+=count
            avg_length= count1/total_words






            n =input('Enter some text: ')
            s=n
            total=0
            e=0
            l=s.split()
            v= len(l)


        print('The average word length is:',round(avg_length,5))


main()