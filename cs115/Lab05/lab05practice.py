"""
Program: CS 115 Lab 5d
Author: Your name
Description: This program draws a graph and identifies turning points.
"""
from graphics import *


def main():
    window_height = 600
    window = GraphWin('Graph', 800, window_height)

    # Open the input file and read the number of points
    pointsfile = open("points-test.txt", "r")
    num_points = int(pointsfile.readline())

    x = 20
    first_y = int(pointsfile.readline())   # get the first y-coordinate
    first_point = Point(x, window_height - first_y)

    x += 10
    second_y = int(pointsfile.readline())
    second_point = Point(x, window_height - second_y)

    x+= 10
    third_y = int(pointsfile.readline())
    third_point=Point(x,window_height- second_y)

    line = Line(first_point, second_point)
    line.setOutline('orange')
    line.draw(window)

    line= Line(second_point,third_point)
    line.setOutline('orange')
    line.draw(window)

    window.getMouse()
    window.close()


main()