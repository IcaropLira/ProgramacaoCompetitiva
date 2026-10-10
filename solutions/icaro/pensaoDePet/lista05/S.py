t = int(input())
for i in range(t):
    n = int(input())
    num = 0
    for i in range(n, -1, -1):
        if i % 2 == 0:
            num = i
            break
    print(num//2)
    