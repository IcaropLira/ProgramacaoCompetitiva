n = int(input())

m = n - 1
grafos = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    grafos[a].append(b)
    grafos[b].append(a)
print(grafos)