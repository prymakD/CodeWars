# your code goes here

import math as mt

def sqrRoot(n):
    x = n
    z = (x + 1) // 2

    while z < x:
        x = z
        z = (x + n // x) // 2

    print(x)

numOfSets = int(input())
count = 0

while count < numOfSets:
    num = int(input())
    sqrRoot(num)
    count += 1
