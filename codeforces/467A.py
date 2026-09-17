t = int(input())

c = 0
for _ in range(t):
    n, m = map(int, input().split())
    if n < m and m-n >=2 :
        c+= 1
print(c)