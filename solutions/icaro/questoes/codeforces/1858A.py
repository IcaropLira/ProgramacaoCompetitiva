from math import floor, ceil

q = int(input())
for _ in range(q):
    n1, n2, n3 = map(int, input().split())
    n1 = n1 + ceil(n3/2)
    n2 = n2 + floor(n3/2)
    if n1> n2:
        print("First")
    elif n2 > n1:
        print("Second")
    else:
        print("Second")