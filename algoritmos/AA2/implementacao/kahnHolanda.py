from collections import deque

def kahn(n, adj):
    grau = [0] * (n+1)
    for v in range(1, n+1):
        for to in adj[v]:
            grau[to] += 1
    fila = deque()

    for v in range(1, n + 1):
        if grau[v] == 0:
            fila.append(v)
    ordem = []

    while fila:
        v = fila.popleft()
        ordem.append(v)
        for to in adj[v]:
            grau[to] -= 1
            if grau[to] == 0:
                fila.append(to)
    return ordem    

n,m = map(int, input().split())

mapa = {i: [] for i in range(1, n + 1)}

for _ in range(m):
    a,b = map(int, input().split())

    mapa[a].append(b)
    

seila = kahn(n, mapa)

if len(seila) != n:
    print("Sandro fails.")
else:
    print(*seila)
