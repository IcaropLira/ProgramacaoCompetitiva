import math

t = int(input())

for _ in range(t):
    n = int(input())
    x = n + 1

    primo = True

    for i in range(2, math.isqrt(x) + 1):
        if x % i == 0:
            primo = False
            break

    print("YES" if primo else "NO")