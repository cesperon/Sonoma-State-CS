"""
Program: Lab 12
Author: Your name
This program will eventually read in a list of students and grades from a text
 file, calculate the students' averages, and print the list of students.
"""
import math

class Student:
    """ A class that holds the data for an individual student """
    def __init__(self, name, scores):
        self.name = name
        self.scores = scores

    def get_average(self):
        """ Return the average grade """
        if self.scores ==[]:
            return None
        else:
            average=  (sum(self.scores))/(len(self.scores))
            return round(average,5)

    def print(self):
        """ Print the student info in the following format:
           Name (12 characters), grades(separated by tabs), average (formatted
           to 5 decimals """

        # Right now, just prints the student name padded out to 12 characters
        string_to_print = self.name.ljust(12)

        # Convert list of integers to strings for printing purposes
        # There are shorter ways to do this, but this is the clearest.
        for score in self.scores:
            string_to_print += '\t' + str(score)

        string_to_print += '\t' + str(self.get_average())

        print(string_to_print)


# A tester program
def main():
    # Try to create and print a student with grades of 8, 9, and 10
    test_student = Student('Test', [8, 9, 10])
    test_student.print()


main()
