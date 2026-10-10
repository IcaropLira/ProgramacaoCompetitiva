#CSES - 1675
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def find(x, pais):
    if pais[x]< 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a, b, pais):
    raiz_a = find(a, pais)
    raiz_b = find(b, pais)

    if raiz_a == raiz_b:
        return False
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return True

def kruskal(n, arestas):
    pais = [-1] * (n+1) 
    arestas.sort()
    custo_total = 0
    arvore = []
    for peso, u , v in arestas:
        if union(u, v, pais):
            custo_total+= peso
            arvore.append((u, v, peso))
            if len(arvore) == n-1:
                break
    if len(arvore) != n-1:
        return None
    return arvore, custo_total

def main():

    n, m = map(int, input().split())

    arestas = []

    for i in range(m):
        a, b, c = map(int, input().split())
        arestas.append((c, a, b))

    krukalres = kruskal(n, arestas)
    if krukalres == None:
        print("IMPOSSIBLE")
    else:
        print(krukalres[1])

main()