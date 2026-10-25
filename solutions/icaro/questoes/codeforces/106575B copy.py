def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a, b , pais):
    ra = find(a, pais)
    rb = find(b, pais)
    if ra == rb:
        return False
    if pais[rb] < pais[ra]:
        ra, rb, = rb, ra
    pais[ra] +=  pais[rb]
    pais[rb] = ra
    return True

def kruskal(n, arestas):
    arestas.sort()
    pais = [-1] * (n+1)
    custo_total = 0
    arvore = []
    for peso, u, v in arestas:
        if union(u, v, pais):
            custo_total += peso
            arvore.append((u, v , peso))
            if len(arvore) == n-1:
                   break
    if len(arvore) != n-1:
        return None
    return arvore, custo_total



n , m, k , c = map(int, input().split())
plataformas = list(map(int, input().split()))
pesos = list(map(int, input().split()))

arestas = []
for i in range(m):
    u, v = map(int, input().split())
    arestas.append((pesos[i], u, v))

if kruskal(n, arestas) != None:
    arvore, custo_total = kruskal(n, arestas)
    if custo_total > c:
        print(-1)
    else:
        print(custo_total)
else:
    print(-1)