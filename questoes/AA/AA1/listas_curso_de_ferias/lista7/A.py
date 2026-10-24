A, B, C = map(int, input().split())

x = ((A + C - 1) // C) * C

if x <= B:
    print(x)
else:
    print(-1)