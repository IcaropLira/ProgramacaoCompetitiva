import sys
input = sys.stdin.readline

def find(x):
    while pai[x] != x:
        pai[x] = pai[pai[x]]
        x = pai[x]
    return x

def union(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return

    if tam[a] < tam[b]:
        a, b = b, a

    pai[b] = a
    tam[a] += tam[b]

t = int(input())

for _ in range(t):
    n, x, y = map(int, input().split())
    p = [0] + list(map(int, input().split()))

    pai = list(range(n + 1))
    tam = [1] * (n + 1)

    for i in range(1, n + 1):
        if i + x <= n:
            union(i, i + x)
        if i + y <= n:
            union(i, i + y)

    ok = True
    for i in range(1, n + 1):
        if find(i) != find(p[i]):
            ok = False
            break

    print("YES" if ok else "NO")