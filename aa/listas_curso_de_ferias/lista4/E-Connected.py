entrada = input().split()
N = int(entrada[0])
M = int(entrada[1])

grafo = []
for _ in range(N):
    grafo.append([])

for _ in range(M):
    entrada = input().split()
    u = int(entrada[0]) - 1 
    v = int(entrada[1]) - 1
    
    grafo[u].append(v)
    grafo[v].append(u)

visitado = [False] * N

def dfs(v):
    visitado[v] = True
    
    for vizinho in grafo[v]:
        if not visitado[vizinho]:
            dfs(vizinho)

componentes = 0

for i in range(N):
    if not visitado[i]:
        dfs(i)
        componentes += 1

print(componentes)