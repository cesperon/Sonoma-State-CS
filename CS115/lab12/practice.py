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

def readfile(filename):
    """
    Reads the entire contents of a file into a single string using
    the read() method.

    Parameter: the name of the file to read (as a string)
    Returns: the text in the file as a large, possibly multi-line, string
    """

    infile = open(filename, "r")  # open file for reading

    # Use Python's file read function to read the file contents
    filetext = infile.read().splitlines()

    infile.close()  # close the file

    return filetext  # the text of the file, as a single string





# A tester program
def main():
    studentlines = readfile("students.txt")

    # Loop over the list of lines from the file and
    # break each line down into a name and scores

    # Loop over the list of lines from the file and
    # break each line down into a name and scores
    sum=0
    for line in studentlines:


        # 1. Split line into a list. If list is empty, break out of the loop.
        list= line.split()


        # 2. The first item in the list is the student's name
        name= list[0]

        # 3. Convert the remaining items in the list into integers

        remaining= list[1:]
        scores= []
        for n in remaining:
            scores.append(int(n))
        # 4. Create a new Student variable with that name and scores
        test_student = Student(name, scores)

        # 5. Call the Student print method to print that student's
        # information
        test_student.print()

        sum+=test_student.get_average()

    total_average= round(sum/20,5)
    print()
    print('overall_average',total_average)







main()