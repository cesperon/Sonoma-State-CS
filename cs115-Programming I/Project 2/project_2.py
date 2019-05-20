"""
    Program: CS 115 Lab 4a_2
    Author: Christian Esperon
    Description: Calculates total votes for Donald Trump and Hillary Clinton and declares
    winner by circling candidates image and loser by crossing out candidates image.
"""
from proj2_support_code import *

def verify_input(x,y):
    for i in range (len(x)):
        if x[i] == y.upper():
            return True



def clicked_trump(x_point,y_point):
    '''
    Verifys if user clicked trumps picture
    Parameters:
    - x_point: x coordinate
    - y_point: y coordinate
    '''


    trump_top_left_x = WINDOW_WIDTH * .25 - 50
    trump_top_left_y = WINDOW_HEIGHT * 0
    width = 100
    height = 100
    trump_top_left = Point(trump_top_left_x, trump_top_left_y)
    trump_bottom_right = Point(trump_top_left_x + width, trump_top_left_y + height)


    if (trump_top_left.getX() <= x_point <= trump_bottom_right.getX() and trump_top_left.getY() <= y_point <=
       trump_bottom_right.getY()):
        return True

def clicked_clinton(x_point, y_point):
    '''
    Verifys if user clicked clintons picture
    Parameters:
    - x_point: x coordinate
    - y_point: y coordinate
    '''

    clinton_top_left_x = WINDOW_WIDTH * .75 - 50
    clinton_top_left_y = WINDOW_HEIGHT * 0
    width = 100
    height = 100
    clinton_top_left = Point(clinton_top_left_x, clinton_top_left_y)
    clinton_bottom_right= Point(clinton_top_left_x + width,clinton_top_left_y + height )

    if (clinton_top_left.getX() <= x_point <= clinton_bottom_right.getX() and clinton_top_left.getY() <= y_point <=
       clinton_bottom_right.getY()):
        return True


def is_state(enteredtext):
    for state in STATE_LIST:
        if enteredtext == state:
            return True

    return False

def states_not_counted():
    counter= 0
    counted = ""

    for state in STATE_LIST:
        counted+= state + " "
        counter+=1
        if counter % 10 ==0:
            counted += "\n"

    return counted

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





def main():

    win= GraphWin('2016 Election Tracker',WINDOW_WIDTH, WINDOW_HEIGHT)

    clin_in_v = 0
    tru_in_v = 0



    trump_img = Image(Point(WINDOW_WIDTH*.25,WINDOW_HEIGHT/6 - 50),"trump.gif")  # Filenames of candidate pics
    trump_img.draw(win)

    clinton_img = Image(Point(WINDOW_WIDTH * .75,WINDOW_HEIGHT/6 -50),"clinton.gif")
    clinton_img.draw(win)

    textbox_trump = Text(Point(WINDOW_WIDTH * .245, WINDOW_HEIGHT/6 +10), "VOTES: " + str(clin_in_v))
    textbox_trump.draw(win)

    textbox_clinton = Text(Point(WINDOW_WIDTH * .75, WINDOW_HEIGHT/6 +10), "VOTES: " + str(tru_in_v))
    textbox_clinton.draw(win)


    inst_textbox = Text(Point(WINDOW_WIDTH * .5, WINDOW_HEIGHT - USER_INSTRUCTIONS_HEIGHT), "Enter a state abbreviation, then click a picture.")
    inst_textbox.draw(win)
    entrybox = Entry(Point(WINDOW_WIDTH * .5,WINDOW_HEIGHT - ENTRYBOX_HEIGHT), 10)
    entrybox.draw(win)

    STATE_LISTbox= Text(Point(WINDOW_WIDTH/2, WINDOW_HEIGHT/2.4),'States Remaining:')
    STATE_LISTbox.draw(win)

    STATE_LISTbox1= Text(Point(WINDOW_WIDTH/2, WINDOW_HEIGHT/2),states_not_counted())
    STATE_LISTbox1.draw(win)



    clin_in_v1=0
    tru_in_v1 =0
    new_list= []
    clinton_total_votes= 0
    trump_total_votes= 0


    try:
        while True:


            c_point = win.getMouse()
            x_c_point = c_point.getX()
            y_c_point = c_point.getY()
            enteredtext = entrybox.getText()


            if enteredtext.upper() in STATE_LIST:


                if clicked_trump(x_c_point,y_c_point) == True:
                    enteredtext = entrybox.getText().upper()
                    x= verify_input(STATE_LIST,enteredtext)
                    if x == True:
                        tru_in_v1 = STATE_VOTES[enteredtext] + tru_in_v


                    tru_in_v = tru_in_v1

                    textbox_trump.setText("VOTES: " + str(tru_in_v))

                    new_list.append(enteredtext)
                    STATE_LIST.remove(enteredtext)
                    STATE_LISTbox1.setText(states_not_counted())


                    if tru_in_v == 270 or tru_in_v > 270:
                        circle_winner(win,Point(WINDOW_WIDTH*.25,WINDOW_HEIGHT/6 - 50))
                        cross_out_loser(win,Point(WINDOW_WIDTH * .75,WINDOW_HEIGHT/6 -50))






                elif clicked_clinton(x_c_point, y_c_point) == True:
                    enteredtext = entrybox.getText().upper()
                    x = verify_input(STATE_LIST,enteredtext)
                    if x == True:
                        clin_in_v1 = STATE_VOTES[enteredtext] + clin_in_v


                    clin_in_v = clin_in_v1

                    textbox_clinton.setText("VOTES: " + str(clin_in_v))
                    new_list.append(enteredtext)
                    STATE_LIST.remove(enteredtext)
                    STATE_LISTbox1.setText(states_not_counted())


                    if clin_in_v == 270 or clin_in_v > 270:
                        circle_winner(win, Point(WINDOW_WIDTH * .75,WINDOW_HEIGHT/6 -50))
                        cross_out_loser(win, Point(WINDOW_WIDTH*.25,WINDOW_HEIGHT/6 - 50))



            elif enteredtext.upper() in new_list:
                print('State Already Entered: '+enteredtext)

            else:
                print('Incorrect State Entered:', enteredtext)


        win.close()
    except(GraphicsError):
        print('Window was manually closed - Restart the application')






main()