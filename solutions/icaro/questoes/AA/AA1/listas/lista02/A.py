n = int(input())

for i in range(n):
    n1, n2, n3 = map(int, input().split())
    n4 = n1 ^ n2 ^ n3
    print(n4)