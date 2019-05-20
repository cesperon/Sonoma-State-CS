'''
Project 2 support code
Author: Dr. Suzanne Rivoire

Constants:
WINDOW_WIDTH, WINDOW_HEIGHT (width and height of graphics window)
IMAGE_WIDTH, IMAGE_HEIGHT (width and height of candidates' pictures)
CLINTON_PIC, TRUMP_PIC (filenames of candidates' pictures)
STATE_VOTES: a dictionary mapping state abbreviations to electoral votes

Functions:
circle_winner: pass it your graphics window and the center of the
   winner's picture (as a Point), and it will circle that person's photo
cross_out_loser: pass it your graphics window and the center of the loser's
   picture (as a Point), and it will circle that person's photo

'''

from graphics import *

WINDOW_WIDTH = 800  # Width and height of graphics window
WINDOW_HEIGHT = 600

IMAGE_WIDTH = 100 # Width and height of candidate pics
IMAGE_HEIGHT = 100

USER_INSTRUCTIONS_HEIGHT = 100 #Height from the bottom of the screen at which the user instructions needs to be displayed
ENTRYBOX_HEIGHT = 50 #Height from the bottom of the screen at which the entry box needs to be displayed

CLINTON_PIC = "clinton.gif" # Filenames of candidate pics
TRUMP_PIC = "trump.gif"

STATE_VOTES = {
    "AL" : 9, # Alabama
    "AK" : 3, # Alaska
    "AZ" : 11, # Arizona
    "AR" : 6, # Arkansas
    "CA" : 55, # California
    "CO" : 9, # Colorado
    "CT" : 7, # Connecticut
    "DE" : 3, # Delaware
    "DC" : 3, # Washington DC
    "FL" : 29, # Florida
    "GA" : 16, # Georgia
    "HI" : 4, # Hawaii
    "ID" : 4, # Idaho
    "IL" : 20, # Illinois
    "IN" : 11, # Indiana
    "IA" : 6, # Iowa
    "KS" : 6, # Kansas
    "KY" : 8, # Kentucky
    "LA" : 8, # Louisiana
    "ME" : 4, # Maine
    "MD" : 10, # Maryland
    "MA" : 11, # Massachusetts
    "MI" : 16, # Michigan
    "MN" : 10, # Minnesota
    "MS" : 6, # Mississippi
    "MO" : 10, # Missouri
    "MT" : 3, # Montana
    "NE" : 5, # Nebraska
    "NV" : 6, # Nevada
    "NH" : 4, # New Hampshire
    "NJ" : 14, # New Jersey
    "NM" : 5, # New Mexico
    "NY" : 29, # New York
    "NC" : 15, # North Carolina
    "ND" : 3, # North Dakota
    "OH" : 18, # Ohio
    "OK" : 7, # Oklahoma
    "OR" : 7, # Oregon
    "PA" : 20, # Pennsylvania
    "RI" : 4, # Rhode Island
    "SC" : 9, # South Carolina
    "SD" : 3, # South Dakota
    "TN" : 11, # Tennessee
    "TX" : 38, # Texas
    "UT" : 6, # Utah
    "VT" : 3, # Vermont
    "VA" : 13, # Virginia
    "WA" : 12, # Washington
    "WV" : 5, # West Virginia
    "WI" : 10, # Wisconsin
    "WY" : 3 # Wyoming
}

STATE_LIST = sorted(list(STATE_VOTES.keys()))

# --- FUNCTIONS ---
def circle_winner(win, winner_center):
    '''
    Circle the winner's photo
    Parameters:
    - win: the window
    - winner_center: the center of the winner's picture (as a Point)
    '''
    outline_width = 6
    circle = Circle(winner_center, IMAGE_HEIGHT / 2 - outline_width)
    circle.setOutline('red')
    circle.setWidth(outline_width)
    circle.draw(win)


def cross_out_loser(win, loser_center):
    '''
    Cross out the loser's photo
    Parameters:
    - win: the window
    - loser_center: the center of the loser's picture (as a Point)
    '''
    for i in range(2):
        deltaX = (-1) ** i * IMAGE_WIDTH / 2
        deltaY = IMAGE_HEIGHT / 2
        line = Line(Point(loser_center.getX() - deltaX, loser_center.getY() - deltaY),
                 Point(loser_center.getX() + deltaX, loser_center.getY() + deltaY))
        line.setFill('red')
        line.setWidth(6)
        line.draw(win)


