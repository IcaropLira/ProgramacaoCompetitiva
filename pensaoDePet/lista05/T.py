from math import lcm

t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    if r < 2*l:
        print(-1, -1)
        continue
    x = l
    y = 2* l
    res = lcm(x, y)
    print(x, y)