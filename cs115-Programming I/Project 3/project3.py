'''
Program: CS 115 Project 3: Racko!
Author:Christian Esperon
Description: Racko is a card game in which the user must try to achieve a hand of cards in
             ascending order before the computer does.First to do so achieves a Racko and
             wins the game.
'''

#Define a global variable to denote the total number of cards.
#In the actual game, this will be equal to 60 but for testing we use smaller numbers
numCards = 9 #9, 12, 60

#Define a global variable to denote the size of rack (number of cards in user's hand).
#In the actual game, this will be equal to 10 but for testing we use smaller numbers
rackSize = 3 #3, 4, 10

import sys
import random

def get_top_card(list):
    """
    Gets the top card from any any given deck.

    Parameter: deck
    Returns: top card from deck
    """
    top_card=list.pop()
    return top_card

def add_card_to_discard(card,discard):
    """
    Adds a card to the discard pile.

    Parameter: unwanted card; discard pile
    Returns: nothing
    """

    discard.append(card)


def find_and_replace(newcard,card2br,hand, discard):
    """
    Adds newcard to hand and places unwanted card into the discard pile.

    Parameter: desired card; card to be replaced; hand; discard pile
    Returns nothing
    """


    for i in range (len(hand)):
        if hand[i] == card2br:
            hand[i]= newcard
            add_card_to_discard(card2br,discard)

def shuffle(card_stack):
    """
    Shuffles any given deck

    Parameter: List(deck of cards)
    Returns: nothing
    """

    random.shuffle(card_stack)


def deal_initial_hands(deck):
    """
    Deals out two hands of cards.

    Parameter: List(deck)
    Returns: Two lists which represent to card hands
    """

    hand1=[]
    hand2=[]
    top_card_user = get_top_card(deck)
    hand1.append(top_card_user)
    top_card_user2=get_top_card(deck)
    hand2.append(top_card_user2)

    while (len(hand1)) < rackSize and (len(hand2)) < rackSize :

        top_card_user = get_top_card(deck)
        hand1.append(top_card_user)
        top_card_user2= get_top_card(deck)
        hand2.append(top_card_user2)


    return hand1,hand2

def check_racko(hand):
    """
    Verifies if the given hand is a sorted list.

    Parameter: hand of cards
    Returns: True or False
    """

    if sorted(hand) == hand:
        return True

    else:

        return False

def replaceDeck(card_stack):
    """
    Takes the discard pile and shuffles it, that then becomes the new deck
    and the top card from new deck becomes the discard pile.
    Parameter: List of numbers in discard pile
    Returns: Two lists the new deck; and new discard pile
    """

    shuffle(card_stack)
    discard_pile=[]

    discard_pile.append(card_stack.pop())


    return discard_pile,card_stack

def computer_play(computer_hand, deck, discard):

    #Define a variable to specify the numbers that can be "allotted" to a single card in the rack
    div = numCards // rackSize

    #print lists corresponding to deck, discard pile and computer's current hand
    print('deck:')
    print(deck)
    print('discard pile:')
    print(discard)
    print()
    print("Computer's current hand:")
    print(computer_hand)



    #randomly decide whether to choose from the discard pile or deck
    #coin = random.random() #import random for this to work
    coin = random.random()
    if coin > 0.5:
        # Show the discard card
        discard_card = get_top_card(discard)
        #Choose a card to kick out
        #First determine index where discard_Card should be inserted.
        #Estimate it by dividing the discard Card with numbers per rack (div)
        print("Computer: Chooses top discard card " + str(discard_card))
        loc = (discard_card - 1) // div

        #Replace by whatever card is in computer's hand at this index
        number_of_card = computer_hand[loc]
        print("Computer: Replacing it with  " + str(number_of_card))

        #Modify the discard pile and the computer's hand
        find_and_replace(discard_card,computer_hand[loc],computer_hand,discard)

        print("Computer's new hand: ")
        print(computer_hand)
        print()


    else:
        # Pick the top card from deck and print it out
        deck_card = get_top_card(deck)
        print("Computer: Chooses top card from the deck " + str(deck_card))

        coin = random.random()
        #Randomly decide whether to keep the deck card or not
        if coin > 0.5:
            # Choose a card to kick out
            # First determine index where deck card should be inserted.
            print("Computer: Chooses top deck card " + str(deck_card))

            loc = (deck_card - 1) // div
            # Replace by whatever card is in computer's hand at this index
            number_of_card = computer_hand[loc]
            print("Computer: Replacing it with " + str(number_of_card))

            #Modify the discard pile and the computer's hand
            find_and_replace(deck_card,computer_hand[loc],computer_hand,discard)
            print("Computer's new hand is:")
            print(computer_hand)
            print()
        else:
            print("Computer: Rejects top deck card " + str(deck_card))

            #Add card to discard pile
            add_card_to_discard(deck_card,discard)
            print("Computer's new hand is:")
            print(computer_hand)
            print()

def human_play(human_hand, deck, discard_pile):
    # print lists corresponding to deck, discard pile and user hand
    print('deck:')
    print(deck)
    print('discard pile:')
    print(discard_pile)
    print('Your current hand:')
    print(human_hand)

    # Retrieve the top card in the discard pile and ask user if they want it
    top_discard = get_top_card(discard_pile)
    print('Do you want this discard card:', top_discard)
    answer = str(input('Enter yes or no:'))

    if answer.lower() == 'yes':
        # Ask the user for the card (number) they want to kick out
        card_2_BR = int(input('Enter the number of the card you want to kick out:'))
        # Modify the user's hand and the discard pile
        find_and_replace(top_discard, card_2_BR, human_hand, discard_pile)

        # Print the user's hand
        print('Your new hand is:')
        print(human_hand)
        print()
    elif answer.lower() == 'no':
        add_card_to_discard(top_discard, discard_pile)
        # Get the top card from deck and print it to show the user what they got
        topcard_deck = get_top_card(deck)
        print('The card you get from the deck is', topcard_deck)
        # Ask the user if they want this card
        second_choice = input("Do you want to keep this card? Enter yes or no: ")
        if second_choice.lower() == 'yes':
            # Ask the user for the card (number) they want to kick out
            card_2_KO = int(input('Enter the number of the card you want to kick out:'))
            # Modify the user's hand and the discard pile
            find_and_replace(topcard_deck, card_2_KO, human_hand, discard_pile)
            # Print the user's hand
            print('Your new hand is:')
            print(human_hand)
            print()
        else:
            # Add card to discard pile
            add_card_to_discard(topcard_deck, discard_pile)

            # Print the user's hand
            print('Your new hand is:')
            print(human_hand)
            print()
    else:
        print("Choice can be only yes or no.")
        sys.exit()


def main():
    random.seed(26)
    # Create a list of integers that represents the deck.
    # This should be numbers from 1 to numCards (see definition of numCards above)
    deck= []
    for i in range (1,numCards+1):

        deck.append(i)


    # shuffle the deck
    shuffle(deck)

    # deal initial hands
    #human_computer[0]= human hand, human_computer[1]= computer hand

    computer_hand, human_hand= deal_initial_hands(deck)
    # create an empty discard pile

    discard_pile=[]

    # Take out top card from the deck to begin the discard pile
    top_card= get_top_card(deck)
    add_card_to_discard(top_card,discard_pile)

    while check_racko(human_hand)!=True and check_racko(computer_hand)!=True:

        if check_racko(computer_hand)== False:
            human_play(human_hand,deck,discard_pile)

            if len(deck) == 0:
                print(" \nUser: WOAH! Deck is empty.Shuffling discard pile and using that as the new deck.")
                # Call replaceDeck to get the lists corresponding to the new deck and discard pile
                discard_pile, deck = replaceDeck(discard_pile)


        if check_racko(human_hand)== False:
            computer_play(computer_hand,deck,discard_pile)

            if len(deck) == 0:
                print(" \nComputer: WOAH! Deck is empty. Shuffling discard pile and using that as the new deck.\n")
                # Call replaceDeck to get the lists corresponding to the new deck and discard pile
                discard_pile, deck=replaceDeck(discard_pile)
    # Outside the while loop. We have a winner. Declare the winner along with the winner's hand.

    if check_racko(human_hand)== True:
        print('HUMAN WINS! with hand of',human_hand)
    else:
        print('COMPUTER WINS! with hand of', computer_hand)


main()