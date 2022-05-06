# a=int(input())
for set in range(int(input())):
    coins = int(input())

    count = 0
    num = 1

    if coins == 2 or coins == 1:
        print(coins)
    else:
        while num <= coins:
            num *= 2
            count = count + 1
        count -= 1
        coins -= (num // 2) -  1
        while coins > 0 and num > 1:
            num = num // 2
            if coins - num >= 0:
                coins -= num
                count = count + 1

        print(count)
