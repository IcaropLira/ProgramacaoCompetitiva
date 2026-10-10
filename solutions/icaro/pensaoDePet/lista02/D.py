from heapq import heappop, heappush
from sys import stdin
input = stdin.readline


def dijkstra(grafo, inicio):
    n = len(grafo)
    dist = [float("inf")] * (n)
    dist[inicio] = 0
    heap = [(0, inicio)]
    while heap:
        distancia_atual, no = heappop(heap)
        if distancia_atual > dist[no]:
            continue
        for peso, vizinho in grafo[no]:
            nova_dist = dist[no] + peso
            if nova_dist < dist[vizinho]:
                dist[vizinho] = nova_dist
                heappush(heap, (nova_dist, vizinho))
    return dist

n , m = map(int, input().split())

grafo = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    grafo[a].append((c,b))

dist = dijkstra(grafo, 1)[1:]

print(*dist)