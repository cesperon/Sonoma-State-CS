"""
    Program: CS 115 Lab 4a_2
    Author: Christian Esperon
    Description: This program draw a few rectangles and fills them.
"""
from graphics import *


def main():
    window = GraphWin('Lab 4a_2', 400, 600)

    palette_top_left_x = 10
    palette_top_left_y = 20
    width = 60
    height = 60
    yellow_top_left = Point(palette_top_left_x, palette_top_left_y)
    yellow_bottom_right = Point(palette_top_left_x + width, palette_top_left_y + height)
    yellow_rectangle = Rectangle(yellow_top_left, yellow_bottom_right)
    yellow_rectangle.setFill('yellow')
    yellow_rectangle.draw(window)

    palette2_top_left_x = 70
    palette2_top_left_y = 20
    width = 60
    height = 60
    pink_top_left = Point(palette2_top_left_x, palette2_top_left_y)
    pink_bottom_right = Point(palette2_top_left_x + width, palette2_top_left_y + height)
    pink_rectangle = Rectangle(pink_top_left, pink_bottom_right)
    pink_rectangle.setFill('pink')
    pink_rectangle.draw(window)

    palette3_top_left_x = 130
    palette3_top_left_y = 20
    width = 60
    height = 60
    blue_top_left = Point(palette3_top_left_x, palette3_top_left_y)
    blue_bottom_right = Point(palette3_top_left_x + width, palette3_top_left_y + height)
    blue_rectangle = Rectangle(blue_top_left, blue_bottom_right)
    blue_rectangle.setFill('blue')
    blue_rectangle.draw(window)



    for i in range(5):
        c_point = window.getMouse()
        x_c_point = c_point.getX()
        y_c_point = c_point.getY()
        if (yellow_top_left.getX() <= x_c_point <= yellow_bottom_right.getX() and
           yellow_top_left.getY() <= y_c_point <= yellow_bottom_right.getY()):
            print('The click with x =', c_point.getX(), 'and y =',
                  c_point.getY(), 'is in the yellow square.')
        elif (pink_top_left.getX() <= x_c_point <= pink_bottom_right.getX() and
              pink_top_left.getY() <= y_c_point <= pink_bottom_right.getY()):
            print('The click with x =', c_point.getX(),'and y=',
                  c_point.getY(), 'is in the pink square.')
        elif (blue_top_left.getX() <= x_c_point <= blue_bottom_right.getX() and
              blue_top_left.getY() <= y_c_point <= blue_bottom_right.getY()):
            print('The click with x =', c_point.getX(),'and y=',
                  c_point.getY(), 'is in the blue square.')
        else:
            print('The click with x =', c_point.getX(), 'and y =',
                  c_point.getY(), 'is not in any of the squares.')

    window.getMouse()
    window.close()

main()