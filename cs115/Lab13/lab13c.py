"""
Program: Lab 13
Author: Christian Esperon
Define and test a basic City class.
"""
import sys


class City:
    def __init__(self,name,population):
        self.name=name
        self.population=population

    def __str__(self):
        return self.name + ' (pop. ' + str(self.population) +')'

    def __lt__(self, other):
        # Return True if the population of self is less than
        # the population of other and return False otherwise
        if self.population < other.population:
            return True

        return False

def print_list(list_to_print):
    '''
    Print the contents of a list.

    Parameter: the list to print
    Returns: nothing
    '''

    for i, item in enumerate(list_to_print):
        print(i, ': ', item, sep="")



def find_index_of_min(L,start_index):
    """
    Parameter: a list L
    Returns: the index of the minimum element of the list
        (returns None if the list is empty)
    """

    if L == [] or start_index > (len(L)-1) :
        return None
    else:
        min = City('Z',float('inf'))
        for i in range(start_index, (len(L))):
            if L[i] < min:
                min = L[i]
                min_index = i
        return min_index

def selection_sort(L):
    '''
    Use the selection sort algorithm to sort a list.
    Parameter: unsorted list
    Sorts the original list that was passed to it -- doesn't return anything.
    '''



    for i in range (len(L)-1):

        min_index= find_index_of_min(L,i)

        x= L[i]

        y= L[min_index]

        L[i]= L[min_index]

        L[min_index]= x


        #print('Swapped elements',i,'and',min_index,'--',x,'and',y)

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





def main():
    #tokyo = City('Tokyo', 13189000)
    #mexico_city = City('Mexico City', 8857188)

    #print(tokyo)
    #print(mexico_city)
    # Print whichever city is larger
    #print('The larger city is:')
    #if mexico_city < tokyo:
        #print(str(tokyo))
    #else:
        #print(mexico_city)

    #testlist = [tokyo, mexico_city]
    #print_list(testlist)

    #selection_sort(testlist)

    #print_list(testlist)

    filename = str(input('Name of input file: '))

    string = readfile(filename)

    cities= []

    for i in range (0,len(string),2):
        city= City(string[i], int(string[i+1]))
        cities.append(city)
    print()
    print('The original list of cities is:')
    print_list(cities)
    print()
    print('The new list of cities is:')
    selection_sort(cities)
    print_list(cities)

main()