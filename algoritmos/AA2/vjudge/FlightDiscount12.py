from collections import deque

def menor_caminho(lista):
    adj = [[] for _ in range(2 * n + 1)]

    def liga(a, b, k):
        if k == 0:
            adj[a].append((b,0))
            return
        ant = a
        for _ in range(k-1):
            adj.append([])
            novo = len(adj) -1
            adj[ant].append((novo, 1))
            ant = novo
        adj[ant].append((b, 1))

    for u in range(1, n+1):
        for v, c in lista[u]:
            liga(u, v, c)
            liga(u + n, v + n, c)
            liga(u, v + n, c//2)

    inf = float("inf")
    dist = [inf] * len(adj)
    dist[1] = 0
    fila = deque([1])

    while fila:
        u = fila.popleft()
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                if w == 0:
                    fila.appendleft(v)
                else:
                    fila.append(v)
    r = min(dist[n], dist[2 * n])
    return r




n, m = map(int, input().split())

lista = [[] for x in range(n+1)]

vistos = set()

for _ in range(m):
    a, b, c = map(int, input().split())

    lista[a].append([b, c])

print(menor_caminho(lista))