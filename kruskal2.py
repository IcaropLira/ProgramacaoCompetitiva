import sys
sys.setrecursionlimit(10**6)

def kruskal(n, arestas):
    arestas.sort()
    pais = [-1] * (n+1)
    custoTotal = 0
    arvore = []
    for p, u, v in arestas:
        if union(u,v,pais):
            custoTotal += p
            arvore.append((u,v,p))
            if len(arvore) == n -1: break
            
    if len(arvore) != n-1:
        return None
    
    return arvore, custoTotal

n = 4
aresta = []
result = kruskal(n,aresta)
if result == None:
    print("Não tem")
else:
    arvore, custo = result
    print("Arestas", arvore)
    print("Custo", custo)
    
def kruskal(n,aresta):
    aresta.sort()
          
    