n = int(input())
for _ in range(n):
    a, b = input().split()
    a = list(a)
    b = list(b)
    a[0], b[0] = b[0], a[0]
    a = "".join(a)
    b = "".join(b)
    print(a+" "+ b)