def dfs(no, grafo, visitado):
    visitado[no] = True
    
    for vizinho in grafo[no]:
        if not visitado[vizinho]:
            dfs(vizinho, grafo, visitado)


def main():
    N, M = map(int, input().split())
    
    grafo = [[] for _ in range(N+1)]
    visitado = [False] * (N+1)
    
    for _ in range(M):
        u, v = map(int, input().split())
        grafo[u].append(v)
        grafo[v].append(u)
    
    componentes = 0
    
    for i in range(1, N+1):
        if not visitado[i]:
            dfs(i, grafo, visitado)
            componentes += 1
    
    print(componentes)