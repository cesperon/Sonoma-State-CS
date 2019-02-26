"""
Program: CS 115 Lab 5b
Author: Christian Esperon
Description: This program draws a line graph.
"""
from graphics import *


def main():
    window_height = 600
    window = GraphWin('Graph', 800, window_height)

    pointsfile = open("points-test.txt", "r")
    num_points = int(pointsfile.readline())

    x = 20
    first_y = int(pointsfile.readline())
    first_point = Point(x, window_height - first_y)

    for i in range(1,num_points):
        second_y = int(pointsfile.readline())
        x+=10
        second_point = Point(x,window_height - second_y)

        line = Line(first_point, second_point)
        line.setOutline('orange')
        line.draw(window)

        # Draw a circle centered at the first point
        circle = Circle(first_point, 1)
        circle.draw(window)

        first_point = second_point  # the first point of the second line

    circle = Circle(first_point, 1)
    circle.draw(window)


    window.getMouse()
    window.close()

main()