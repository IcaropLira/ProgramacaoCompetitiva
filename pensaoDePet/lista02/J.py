def resolver(n, m):
    if n >= m:
        return n - m
    if m % 2 == 0:
        return 1 + resolver(n, m // 2)
    else:
        return 1 + resolver(n, m + 1)

n, m = map(int, input().split())
print(resolver(n, m))