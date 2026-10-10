def dfs(no, grafo, visitado):
    visitado[no] = True
    size = 1

    for vizinho in grafo[no]:
        if not visitado[vizinho]:
            size += dfs(vizinho, grafo, visitado)
    
    return size


def main():
    N, M = map(int, input().split())

    grafo = [[] for _ in range(N)]
    visitados = [False] * N

    for _ in range(M):
        u, v = map(int, input().split())
        grafo[u].append(v)
        grafo[v].append(u)

    for i in range(N):
        if not visitados[i]:
            size = dfs(i, grafo, visitados)
            print(size)

main()