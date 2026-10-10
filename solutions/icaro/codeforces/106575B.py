import heapq

n , m, k , c = map(int, input().split())
plataformas = list(map(int, input().split()))
pesos = list(map(int, input().split()))

grafo = [[] for i in range(m+1)]
for i in range(m):
    u, v = map(int, input().split())
    grafo[u].append((pesos[i], v))
    grafo[v].append((pesos[i], u))

print(pesos)


distancias = [float("inf") for i in range(m+1)]
distancias[1] = 0
fila = [(0, 1)]
while fila:
    da, va = heapq.heappop(fila)
    if da > distancias[va]:
        continue
    for vizinho, peso in grafo[va]:
        distancia = da + peso

        if distancia < distancias[vizinho]:
            distancias[vizinho] = distancia
            heapq.heappush(fila, (distancia, vizinho))
print(distancias)
