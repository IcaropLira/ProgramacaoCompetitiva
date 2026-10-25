qnts = int(input())

for _ in range(qnts):
    a, b = map(int, input().split())

    x = a
    y = b
    c = 0
    if a == b:
        print(0)

    elif (a % b == 0 and (a // b) % 2 == 0 ) or ( b % a == 0 and (a // b) % 2 == 0 ):
        while x != b:
            if a > b:
                if x % 8 == 0:
                    x //= 8
                    c += 1
                elif x % 4 == 0:
                    x //= 4
                    c += 1
                elif x % 2 == 0:
                    x //= 2
                    c += 1
            if a < b:
                if y % 8 == 0:
                    x *= 8
                    y //= 8
                    c += 1
                elif y % 4 == 0:
                    x *= 4
                    y //= 4
                    c += 1
                elif y % 2 == 0:
                    x *= 2
                    y //= 2
                    c += 1
        print(c)

    else:
        print(-1)