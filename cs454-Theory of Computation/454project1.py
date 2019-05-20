# cs454 project 1

# Author(s): Christian Esperon, Hector Alonzo- Torres

# Description: User is asked to input either 1, 2 or q. Selecting 1
# will solve the problem asked in problem 1 of the project, selecting
# 2 will solve the problem asked in problem 2 of the project, q will quit
# any other input besides 1 or 2 will exit the program as well.

# Queue class
class Queue:

    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)


# Problem 1
# checks to see if string is in the language
def accepts(dfa, s):

    state = 0
    for c in s:
        state = dfa[state][c]

    if state == 37:
        return False
    else:
        return True


# input dfa and string length, computes the number of strings length s
# that start from state 0 and end in an accepting state
def count(dfa, s):

    prev = []

    # initialize prev vector, state 37 is only state that is not accepting
    for i in range(len(dfa)):
        if i != 37:
            prev.append(1)
        else:
            prev.append(0)

    # initialize current vector
    _next = []

    for k in range(s):
        for j in range(len(dfa)):
            # get values from prev vector and add them up to get values for _next vector
            a = prev[dfa[j]['a']]
            b = prev[dfa[j]['b']]
            c = prev[dfa[j]['c']]
            var = a+b+c
            _next.append(var)

        prev = _next
        _next = []

    print(prev[0])


# Problem 2

def minstring(k, s):

    # create an instance of queue to perform bfs
    q = Queue()
    # mod to be used in delta
    mod = k
    # visited is a boolean array which indicates if a state has been visited
    visited = []
    # parent array is used to hold the parent node of visited nodes
    parent = []
    # label array used to hold the transitions from state to state
    label = []

    # initialize visited, parent and label arrays
    for i in range(k+1):
        visited.append(0)
        parent.append(0)
        label.append(0)

    # set starting state k as visited
    visited[k] = 1

    # put the starting state into the queue
    q.enqueue(k)

    # perform bfs until queue size is empty
    while q.size() != 0:
        k = q.dequeue()
        for j in range(len(s)):
            # equation to find next state
            _next = (k * 10 + s[j]) % mod
            if _next == 0:
                visited[_next] = 1
                parent[_next] = k
                label[_next] = s[j]
                # because we've reached the accepting state we must pop off all the
                # items in the queue to break out of while loop
                for s in range(q.size()):
                    q.dequeue()
                break

            elif visited[_next] != 1:
                visited[_next] = 1
                label[_next] = s[j]
                parent[_next] = k
                q.enqueue(_next)

    # array to hold labels as you trace through parent array
    solution = []

    # if accepting state is never reached then print no solution
    if _next != 0:
        print('no solution')
    # else trace parent from accepting state until starting state is reached
    # keep track of inputs as you trace back to start state and append to solution array
    else:
        i = 0
        while parent[i] != 0:
            solution.append(label[i])
            i = parent[i]

    # reverse solution array to get correct answer
    solution.reverse()

    for l in range(len(solution)):
        print(solution[l], end='')


def main():

    # dfa that accepts language: substring of length 4 of w, all three letters
    # a,b,c occur at least once. Represented as a python dictionary
    dfa = {0: {'a': 1, 'b': 2, 'c': 3},
           1: {'a': 4, 'b': 5, 'c': 6},
           2: {'a': 7, 'b': 8, 'c': 9},
           3: {'a': 10, 'b': 11, 'c': 12},
           4: {'a': 38, 'b': 13, 'c': 14},
           5: {'a': 15, 'b': 16, 'c': 17},
           6: {'a': 18, 'b': 19, 'c': 20},
           7: {'a': 21, 'b': 22, 'c': 23},
           8: {'a': 24, 'b': 39, 'c': 25},
           9: {'a': 27, 'b': 26, 'c': 28},
           10: {'a': 29, 'b': 30, 'c': 31},
           11: {'a': 32, 'b': 33, 'c': 34},
           12: {'a': 35, 'b': 36, 'c': 40},
           13: {'a': 37, 'b': 37, 'c': 17},
           14: {'a': 37, 'b': 19, 'c': 37},
           15: {'a': 37, 'b': 37, 'c': 23},
           16: {'a': 37, 'b': 37, 'c': 25},
           17: {'a': 27, 'b': 26, 'c': 28},
           18: {'a': 37, 'b': 30, 'c': 37},
           19: {'a': 32, 'b': 33, 'c': 34},
           20: {'a': 37, 'b': 36, 'c': 37},
           21: {'a': 37, 'b': 37, 'c': 14},
           22: {'a': 37, 'b': 37, 'c': 17},
           23: {'a': 18, 'b': 19, 'c': 20},
           24: {'a': 37, 'b': 37, 'c': 23},
           25: {'a': 27, 'b': 37, 'c': 37},
           26: {'a': 32, 'b': 37, 'c': 37},
           27: {'a': 29, 'b': 30, 'c': 31},
           28: {'a': 35, 'b': 37, 'c': 37},
           29: {'a': 37, 'b': 13, 'c': 37},
           30: {'a': 15, 'b': 16, 'c': 17},
           31: {'a': 37, 'b': 19, 'c': 37},
           32: {'a': 21, 'b': 22, 'c': 23},
           33: {'a': 24, 'b': 37, 'c': 37},
           34: {'a': 27, 'b': 37, 'c': 37},
           35: {'a': 37, 'b': 30, 'c': 37},
           36: {'a': 32, 'b': 37, 'c': 37},
           37: {'a': 37, 'b': 37, 'c': 37},
           38: {'a': 37, 'b': 37, 'c': 37},
           39: {'a': 37, 'b': 37, 'c': 37},
           40: {'a': 37, 'b': 37, 'c': 37}
           }

    option = input("Enter 1 for task 1, Enter 2 for task 2 or q to quit""\n")

    while option != 'q':
        if option == '1':

            l_input = int(input("Please enter integer n <= 300: "))

            count(dfa, l_input)
            print('\n')

        if option == '2':
            k = int(input("Please enter integer n <= 99999  "))

            s = list(map(int, input("enter digits permitted with no commas ").split()))

            minstring(k, s)
            print('\n')

        option = input("Enter 1 for task 1, 2 for task 2 or q to quit""\n")


main()
