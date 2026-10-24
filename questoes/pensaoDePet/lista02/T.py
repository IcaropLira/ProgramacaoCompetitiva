from heapq import heappop, heappush

def dijkstra(grafo, inicio):
    n = len(grafo)
    dist = [float("inf")] * n
    dist[inicio] = 0
    heap = [(0, inicio)]
    pai = [-1] * (n+1)
    while heap:
        distancia_atual, no = heappop(heap)
        if distancia_atual > dist[no]:
            continue
        for peso, vizinho in grafo[no]:
            nova_dist = dist[no] + peso
            if nova_dist < dist[vizinho]:
                pai[vizinho] = no
                dist[vizinho] = nova_dist
                heappush(heap, (nova_dist, vizinho))

    return dist, pai

def main():
    n, m = map(int, input().split())
    grafo = [[]for i in range(n+1)]
    for i in range(m):
        a, b, c = map(int, input().split())
        grafo[a].append((c,b))
        grafo[b].append((c,a))
    dist, pai = dijkstra(grafo,1)
    caminho = []
    atual = n
    if dist[n] == float("inf"):
        print(-1)
        return
    while atual != -1:
        caminho.append(atual)
        atual = pai[atual]
    caminho.reverse()
    print(*caminho)
main()