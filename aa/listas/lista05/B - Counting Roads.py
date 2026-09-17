import sys

N, M = map(int, sys.stdin.readline().split())

cidades = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, sys.stdin.readline().split())
    cidades[a-1].append(b)
    cidades[b-1].append(a)
for i in cidades:
    sys.stdout.write(f"{len(i)}\n")