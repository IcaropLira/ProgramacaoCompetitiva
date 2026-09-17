#Contar componentes conexos em um grafo não-direcionado com
#N vértices (1 até N)
#M arestas
#Descobrir quantos componentes conexos existem

def dfs(no):
    visitado[no] = True
    
    for vizinho in grafo[no]:
        if not visitado[vizinho]:
            dfs(vizinho)


def main():
    N, M = map(int, input().split())
    
    global grafo, visitado
    grafo = [[] for _ in range(N+1)]
    visitado = [False] * (N+1)
    
    for _ in range(M):
        u, v = map(int, input().split())
        grafo[u].append(v)
        grafo[v].append(u)
    
    componentes = 0
    
    for i in range(1, N+1):
        if not visitado[i]:
            dfs(i)
            componentes += 1
    print(componentes)


main()