import bisect

N, M = map(int,input().split())
cidades = list(map(int, input().split()))
torres = list(map(int, input().split()))

distancia = 0
for i in cidades:
    posicao = bisect.bisect_left(torres, i)
    dist = float('inf')

    if posicao < M:
        dist = min(dist, abs(i - torres[posicao]))
    
    if posicao > 0:
        dist = min(dist, abs(i - torres[posicao -1]))
    
    distancia = max(distancia, dist)


print(distancia)