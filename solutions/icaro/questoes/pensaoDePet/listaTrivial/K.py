n, m = map(int, input().split())
c = 0
while m >= n:
    c += 1
    m *= 2
    n *=3 

print(c)