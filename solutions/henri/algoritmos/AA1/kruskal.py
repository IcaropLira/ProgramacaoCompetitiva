def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a,b,pais):
    raiz_a = find(a, pais)
    raiz_b = find(b, pais)
    
    if raiz_a == raiz_b:
        return False
    
    if pais[raiz_b] < pais[raiz_a]:
        raiz_a, raiz_b = raiz_b, raiz_a
        
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    
    return True

def tamanho(x, pais):
    raiz = find(x, pais)
    return -1 * pais[raiz]

def kruskal(n, arestas):
    arestas.sort()
    pais = [n] * (n + 1)
    custo_total = 0
    arvore = []
    for peso, u, v in arestas:
        if union(u,v,pais):
            custo_total += peso
            arvore.append((u,v,peso))
            
            if len(arvore) == n-1: break
    
    if len(arvore) != n-1:
        return None
    
    return arvore, custo_total

n = 4
aresta = [(1,1,2),(4,1,3),(2,2,3),(3,2,4),(5,3,4)]
result = kruskal(n,aresta)

if result == None:
    print("Não tem")
else:
    arvore, custo = result
    print("Arestas", arvore)
    print("Custo", custo)
    
n = 9
aresta = [(4,1, 2), (11,2,8), (8,1, 8), (8,2,3), (1,8,7), (7,8,9), (2,9,3), (6,9,7), (2,7,6), (4,3,6), (7,3,4), (14,4,6), (9,4,5), (10,6,5)]
result = kruskal(n,aresta)

if result == None:
    print("Não tem")
else:
    arvore, custo = result
    print("Arestas", arvore)
    print("Custo", custo)
    
