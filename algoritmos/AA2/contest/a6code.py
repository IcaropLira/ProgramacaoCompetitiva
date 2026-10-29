import sys

sys.setrecursionlimit(20000)
input = sys.stdin.readline

def dfs(u):
    pretos = 0
    brancos = 0
    resposta = 0

    if string[u -1] == 'B':
        pretos += 1
    else:
        brancos += 1

    for v in filhos[u]:
        p, b, r = dfs(v)
        resposta += r
        pretos += p
        brancos += b

    if pretos == brancos:
        resposta += 1

    return pretos, brancos, resposta

t = int(input())

for _ in range(t):
    n = int(input())
    filhos = {i: [] for i in range(1, n + 1)}
    pais = list(map(int, input().split()))

    string = input()
    
    for i in range(len(pais)):
        filhos[pais[i]].append(i+2)

    _,_,resposta = dfs(1)

    print(resposta)