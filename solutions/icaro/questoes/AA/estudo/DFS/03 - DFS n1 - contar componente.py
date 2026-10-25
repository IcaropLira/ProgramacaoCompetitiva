def dfs(no, grafo, visitado):
    visitado[no] = True
    
    for vizinho in grafo[no]:
        if not visitado[vizinho]:
            dfs(vizinho, grafo, visitado)

def main():
    N, M = map(int, input().split())

    grafo = [[] for _ in range(N)]
    visitado = [False] * N

    for _ in range(M):
        u, v = map(int, input().split())
        grafo[u].append(v)
        grafo[v].append(u)
    
    componentes = 0

    for no in range(N):
        if not visitado[no]:
            dfs(no, grafo, visitado)
            componentes += 1
    
    print(componentes)

main()