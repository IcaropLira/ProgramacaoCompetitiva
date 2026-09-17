from heapq import heappush, heappop
from sys import stdin
input = stdin.readline

def dijkstra(inicio, grafo):
    n = len(grafo) - 1
    dist = [[10**18, 10**18] for _ in range(n+1)]
    dist[inicio][0] = 0
    heap = [(0,inicio, 0)]
    while heap:
        distancia_atual, no, usado = heappop(heap)

        if distancia_atual > dist[no][usado]:
            continue

        if no == len(grafo)-1 and usado:
            return distancia_atual
        for peso, vizinho in grafo[no]:
            if distancia_atual + peso <dist[vizinho][usado]:
                dist[vizinho][usado] = peso + distancia_atual
                heappush(heap,(dist[vizinho][usado], vizinho, usado))

            if usado == 0:
                novo = distancia_atual + peso//2 
                if novo < dist[vizinho][1]:
                    dist[vizinho][1] = novo
                    heappush(heap, (novo, vizinho, 1))           
            


def main(): 
    n , m = map(int, input().split())
    grafo = [[] for i in range(n+1)]
    for i in range(m):
        a, b, c = map(int, input().split())
        grafo[a].append((c,b))

    print(dijkstra(1, grafo))
main()