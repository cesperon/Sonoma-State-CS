# import matplotlib.pyplot as plt
import math
import random
import timeit

def gcd(x, y):

    j = 0

    while y != 0:
        (x, y) = (y, x % y)
        j = j + 1
    # print "number of mods", j
    # print "gcd is", x
    return j


def intcheck(m, n,):

    k = 0

    t = min(m, n)

    while t > 0:

        if m % t != 0:
            k = k + 1
        if m % t == 0 and n % t != 0:
            k = k + 1

        if m % t == 0 and n % t == 0:
            k = k + 2
            return k

        t = t - 1


def fib(n, x):
    a = 0
    b = 1
    x.append(a)
    x.append(b)
    for i in range(1, n):
        c = a+b
        x.append(c)
        a = c
        b = c + b
        x.append(b)
    return x


def sieve(n):
    A = []
    L = []

    start = timeit.default_timer()

    for p in range(0, n+1):
        A.append(p)
    for p in range(1, int(math.floor(math.sqrt(n+1)))):
        p2 = p+1
        if A[p2] != 0:
            j = p2 * p2
        while j < n:
            A[j] = 0
            j += p2

    for p in range(2, n):
        if A[p] != 0:
           L.append(A[p])

    stop = timeit.default_timer()

    return stop-start


def sieve2(n):
    A = []
    L = []

    count = 0

    for p in range(0, n+1):
        A.append(p)
    for p in range(1, int(math.floor(math.sqrt(n+1)))):
        p2 = p+1
        if A[p2] != 0:
            j = p2 * p2
        while j < n:
            A[j] = 0
            j += p2
            count = count + 1

    for p in range(2, n):
        if A[p] != 0:
           L.append(A[p])

    return count


def mdavg(x):

    s = 0.0

    for i in range(1, x+1):
        s = s + gcd(x, i)
        # print(s)
    # print(s/x)
    return s/x


def davg(x):

    s = 0.0

    for i in range(1, x+1):
        s = s + intcheck(x, i)

    return s/x


def mdworst(x):

    arr1 = []
    s = 0.0

    for i in range(0, len(x)-1):
        s = gcd(x[i+1], x[i])
        arr1.append(s)
        s = 0.0

    return s


def commonElements(list1, list2):
    result = []
    count = 0
    list1.sort()
    list2.sort()
    for element in list1:
        count = count + 1
        if element in list2:
            count = count + 1
            result.append(element)
    return count


def main():

    arr1 = []
    arr2 = []

    for n in range(1, 101):
        arr1.append(mdavg(n))
        arr2.append(n)

    # plt.scatter(arr2, arr1, label='Euclids', color='blue', marker='*')

    # plt.xlabel('n')
    # plt.ylabel('average number of mods')
    # plt.title('average class efficiency for euclids')

    arr3 = []
    arr4 = []

    for k in range(1, 101):
        arr3.append(davg(k))
        arr4.append(k)

    # plt.scatter(arr4, arr3, label='Consecutive Integer', color='blue', marker='*')

    # plt.xlabel('n')
    # plt.ylabel('average number of mods')
    # plt.title('average class efficiency for consecutive integer')

    arr5 = []
    fib(20, arr5)

    arr6 = []
    arr7 = []

    mc = 0
    for i in range(0, len(arr5)-1):
        mc = gcd(arr5[i+1], arr5[i])
        arr6.append(mc)
        arr7.append(i+1)
        mc = 0

    # plt.scatter(arr7, arr6, label='Consecutive Integer', color='blue', marker='*')
    # plt.xlabel('n')
    # plt.ylabel('number of mods for euclids using fibonacci sequence')
    # plt.title('worst case efficiency for euclids')

    arr8 = []

    arr9 = []

    for i in range(0, 101):
        arr8.append(sieve(i))
        arr9.append(i)

    # plt.scatter(arr9, arr8, label='sieve of eratosthenes', color='blue', marker='*')
    # plt.xlabel('n')
    # plt.ylabel('run time')
    # plt.title('run time of n using sieve of eratosthenes')

    arr10 = []

    arr11 = []

    for i in range(0, 101):
        arr10.append(sieve2(i))
        arr11.append(i)

    # plt.scatter(arr11, arr10, label='sieve of eratosthenes', color='blue', marker='*')
    # plt.xlabel('n')
    # plt.ylabel('number of basic operations')
    # plt.title('number of basic operations of n using sieve of eratosthenes')

    lst1 = []
    lst2 = []
    lst3 = []
    lst4 = []

    g= 0
    g = commonElements(lst1, lst2)

    for i in range(0, 101):
        lst1.append(random.randint(0, i))
        lst2.append(random.randint(0, i))
        g = commonElements(lst1, lst2)
        lst4.append(g)
        lst3.append(i)
        del lst1[:]
        del lst2[:]

    # plt.scatter(lst4, lst3, label='Common Elements of Sorted List', color='blue', marker='*')
    # plt.xlabel('n')
    # plt.ylabel('number of basic operations')
    # plt.title('number of basic operations of n using Common Elements of Sorted List')

main()