import sys
sys.setrecursionlimit(2000)

def find(x,pais):
    x -= 1
    if pais[x]<0:
        return x
    pais[x] = find(pais[x],pais)
    return pais[x]

def union(a,b,pais):
    ra = find(a,pais)
    rb = find(b,pais)
  
    if ra == rb:
        return False
    
    if pais[rb] < pais[ra]:
        ra, rb = rb, ra
    
    pais[ra]+= pais[rb]
    pais[rb] = ra

    return True

def main():
    n,m = [int(x) for x in input().split()]
    pais = [-1]*n
    grafo = []
    for i in range(m):
        a, b = [int(x)for x in input().split()]
        union(a,b,pais)
        grafo.append((a,b))
    faltando = []
    novos = []
    for i in range(len(pais)):
        if pais[i]<0:
            faltando.append(i)
    saida = len(faltando) -1
    print(saida)

    for j in range(0,len(faltando),2):
        a = faltando[j]
        if j < len(faltando):
            b = faltando[j+1]
        
        else: b = faltando[j-1]
        
        print(a+1,b+1)
main()