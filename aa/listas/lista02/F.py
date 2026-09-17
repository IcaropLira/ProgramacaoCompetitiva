qnts = int(input())

for _ in range(qnts):
    num = int(input())
    n = 1
    while n * 2 <= num:
        n *= 2
    
    print(n - 1)