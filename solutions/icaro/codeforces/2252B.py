t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    Z = 0
    O = 0

    for c in s:
        if c == '0':
            Z += 1
        else:
            O += 1

    D = Z - O

    if abs(D) > 2:
        print(-1)
        continue

    m = 1
    for i in range(1, n):
        if s[i] != s[i - 1]:
            m += 1

    if m % 2 == 0:
        dm = 0
    else:
        if s[0] == '0':
            dm = 1
        else:
            dm = -1

    if abs(D - dm) <= 1:
        L = m
    else:
        if m % 2 == 0:
            L = m - 1
        else:
            if abs(D) <= 1:
                L = m - 1
            else:
                L = m - 2

    print(n - L)