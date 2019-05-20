'''
Author:Christian Esperon

'''


def get_top_card(list):

    top_card=list.pop()

    return top_card

def add_card_to_discard(card,discard):

    discard.append(card)


def find_and_replace(newcard,card2br,hand, discard):


    for i in range (len(hand)):
        if hand[i] == card2br:
            hand[i]= newcard
            add_card_to_discard(card2br,discard)





import sys
import random

def main():
    # create a list of integers that represents a deck
    deck = [8, 3, 2, 4]

    # Assign hand to the user
    human_hand = [5, 1, 7, 6]

    # create an empty discard pile
    discard_pile= []


    # Take out top card from the deck to begin the discard pile
    top_card= get_top_card(deck)

    add_card_to_discard(top_card, discard_pile)

    u=deal_initial_hands(deck)
    print(u)





    while True:

        # print lists corresponding to deck, discard pile and user hand
        print('deck:')
        print(deck)



        print('discard pile:')
        print(discard_pile)

        print('Your current hand:')
        print(human_hand)


        # Retrieve the top card in the discard pile and ask user if they want it
        top_discard= get_top_card(discard_pile)


        print('Do you want this discard card:', top_discard)

        x= str(input('Enter yes or no: '))



        # Ask the user for the card (number) they want to kick out
        if x.lower() == 'yes':
            card2br = int(input('Enter the number of the card you want to kick out: '))
        # Modify the user's hand and the discard pile
            find_and_replace(top_discard,card2br,human_hand,discard_pile)



        # Print the user's hand
            print('Your new hand is:')
            print(human_hand)
            print()
        elif x.lower()=='no':
            add_card_to_discard(top_discard,discard_pile)
            # Get the top card from deck and print it to show the user what they got
            top_deck = get_top_card(deck)
            print('The card you get from the deck is',top_deck)
            # Ask the user if they want this card
            second_choice = input("Do you want to keep this card? Enter yes or no:  ")
            if second_choice.lower() == 'yes':
            # Ask the user for the card (number) they want to kick out
                card2br2= int(input('Enter the number of the card you want to kick out:'))

            # Modify the user's hand and the discard pile
                find_and_replace(top_deck,card2br2,human_hand,discard_pile )

            # Print the user's hand
                print('your new hand is:')
                print(human_hand)
                print()
            else:
        # Add card to discard pile
                add_card_to_discard(top_deck,discard_pile)

        # Print the user's hand
                print('Your new hand is:')
                print(human_hand)
                print()
        else:
            print("Choice can be only yes or no.")
            sys.exit()

        if len(deck) == 0:
            print(" \nWOAH! Deck is empty. Exiting")
            sys.exit()



main()