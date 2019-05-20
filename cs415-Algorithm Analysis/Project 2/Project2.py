import sys
# task 1 implement karatsuba algorithm using list of integers


# removes leading zeroes in list
def remove(a):

    sum = a
    i = 0
    count = 0
    while sum[i] == 0:
        count += 1
        i += 1
    sum.reverse()
    for k in range(count):
        sum.pop()
    sum.reverse()

    return sum


# subtracts two integers represented as lists
def sub(a, b):

    subtraction = 0

    borrow = 0

    c = []

    if len(a) < len(b):
        offset = len(b) - len(a)
        padinfront(a, offset)

    if len(b) < len(a):
        offset = len(a) - len(b)
        padinfront(b, offset)

    a.reverse()
    b.reverse()

    for i in range(0, len(a)):

        if a[i] < b[i]:
            if borrow != 0:
                if a[i] == 0:
                    subtraction = 9 - b[i]
                    c.append(subtraction)
                else:
                    subtraction = a[i] + 9 - b[i]
                    c.append(subtraction)

            else:
                borrow = 1
                subtraction = a[i] + 10 - b[i]
                c.append(subtraction)
        elif a[i] == b[i]:
            if borrow != 0:
                if a[i] == 0:
                    subtraction = 9 - b[i]
                    c.append(subtraction)
                else:
                    subtraction = a[i] + 9 - b[i]
                    c.append(subtraction)
            else:
                c.append(0)
        elif a[i] > b[i]:
            subtraction = (a[i] - borrow) - b[i]
            c.append(subtraction)
            borrow = 0

    a.reverse()
    b.reverse()
    c.reverse()

    return c


# adds two integers represented as lists
def add(a, b):

    addition = 0

    dividebyten = 0

    remainder = 0

    carry = 0

    c = []

    if len(a) < len(b):
        offset = len(b) - len(a)
        padinfront(a, offset)

    if len(b) < len(a):
        offset = len(a) - len(b)
        padinfront(b, offset)

    a.reverse()
    b.reverse()

    for i in range(0, len(a)):

        addition = a[i] + b[i] + carry

        dividebyten = addition // 10

        if dividebyten != 0:
            remainder = addition % 10
            carry = dividebyten
            c.append(remainder)
            if i == len(a) - 1 and carry != 0:
                c.append(carry)

        if dividebyten == 0:
            c.append(addition)
            carry = 0

    a.reverse()
    b.reverse()
    c.reverse()

    return c


# pads lists with 0's in the front of array
def padinfront(a, offset):
    a.reverse()

    for i in range(0, offset):
        a.append(0)

    a.reverse()

    return a


# append param number of zeroes to list
def zeroPad(a, param):
    for i in range(0, param):
        a.append(0)

    return a


# Function for karatsuba multiplication.
def k_multiply(a, b):

    # base case once both lists a and b are of size one then multiply digits directly
    # and store result in list
    if len(a) == 1 and len(b) == 1:

        var = a[0] * b[0]
        var1 = [int(x) for x in str(var)]
        return var1

    # if list lengths are uneven pad with 0's
    if len(a) < len(b):
        offset = len(b) - len(a)
        padinfront(a, offset)

    # if list b is less than list a in length pad with 0's
    if len(b) < len(a):
        offset = len(a) - len(b)
        padinfront(b, offset)

    # pad a and b with zero if they have odd number of digits
    if len(a) % 2 != 0:
        padinfront(a, 1)
        padinfront(b, 1)

    # us length of list to determine slice of list
    n = len(a)
    j = n // 2

    # slice list to get values used in recursive call
    a1 = a[0: j]
    a0 = a[j: n]
    b1 = b[0: j]
    b0 = b[j: n]

    # following variables presented in lecture

    # c2 = a1 * b1
    c2 = k_multiply(a1, b1)

    # c0 = a0 * b0
    c0 = k_multiply(a0, b0)

    # a1 + a0 stores result in res1
    res1 = add(a1, a0)

    # b1 + b0 stores result in res2
    res2 = add(b1, b0)

    # recursively calling k multiply on (a1 + a0) * (b1 + b0)
    k = k_multiply(res1, res2)

    # (c2 + c0)
    ac_plus_bd = add(c2, c0)

    # (a1 + a0) * (b1 + b0) - (c2 + c0)
    c1 = sub(k, ac_plus_bd)

    # append n_padding 0s to c2/c2*10^n
    A = zeroPad(c2, n)

    # append nby2_padding to c1/c1*10^(n/2)
    B = zeroPad(c1, j)

    # c2(10^n) + c1(10^(n/2))
    c2plus_c1 = add(c2, B)

    # c2(10^n) + c1(10^(n/2)) + c0
    final_product = add(c2plus_c1, c0)

    return final_product


# task 2 implement exponentiation recursive algorithm using karatsuba
# for intermediate steps

# function used to convert list into int to used in exp not karatsuba
def convert2int(l):

    str1 = ''.join(str(e) for e in l)

    return str1


# exponentiation function that uses karatsuba for intermediate steps
def exp(var, n):

    # converts int into a list of integers that are acceptable
    # for karatsuba algorithm
    var1 = [int(x) for x in str(var)]

    # multiply var1*var1 to be used in exp recursive call
    var1x2 = k_multiply(var1, var1)

    # convert to int because exp takes int as parameter
    convar1 = convert2int(var1x2)

    # base case: when n = 0 append 1 to list c
    if n == 0:
        c = []
        c.append(1)
        return c

    # case when n is even
    elif n % 2 == 0:
        # call exp on var*var, n/2
        return exp(convar1, n / 2)

    # handles case when n is not even
    else:
        # call exp on var*var, (n-1)/2
        quickP = exp(convar1, (n - 1) / 2)
        # multiply var * result above
        return k_multiply(var1, quickP)


def main():

    print('\n')
    option = input("Please Enter 1 for Karatsuba Multiplication, 2 for Exponentiation, or q to Quit."'\n')
    print('\n')

    while option != 'q':
        if option == '1':
            num1 = input("Please enter an integer no larger than 1000."'\n')
            print('\n')
            num2 = input("Please enter another integer no larger than 1000."'\n')
            print('\n')

            A = []
            B = []

            for i in str(num1):
                A.append(int(i))

            for i in str(num2):
                B.append(int(i))
            print("You entered option 1")
            v = k_multiply(A, B)
            remove(v)
            for i in range(len(v)):
                print(v[i], end=" ")
            print('\n')

        if option == '2':
            a = int(input("Please enter an integer no larger than 1000."'\n'))
            print('\n')
            b = int(input("Please enter another integer no larger than 1000."'\n'))
            print('\n')
            m = exp(a, b)
            remove(m)
            for i in range(len(m)):
                print(m[i], end=" ")
            print('\n')

        option = input("Please Enter 1 for Karatsuba Multiplication, 2 for Exponentiation, or q to Quit."'\n')
        print('\n')

    sys.exit()


main()