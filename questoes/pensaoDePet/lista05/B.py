def main():
    n = int(input())
    a = list(map(int, input().split()))

    c1 = c2 = c3 = c4 = 0

    for x in a:
        if x == 1:
            c1 += 1
        elif x == 2:
            c2 += 1
        elif x == 3:
            c3 += 1
        else:
            c4 += 1

    taxis = c4

    taxis += c3
    c1 = max(0, c1 - c3)

    taxis += c2 // 2
    c2 %= 2

    if c2:
        taxis += 1
        c1 = max(0, c1 - 2)

    taxis += (c1 + 3) // 4

    print(taxis)

main()