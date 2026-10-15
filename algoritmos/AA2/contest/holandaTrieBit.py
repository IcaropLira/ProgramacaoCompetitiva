import sys
input = sys.stdin.readline

B = 30
filho = [[0, 0]]

def reinicia():
    filho[:] = [[0, 0]]

def insere(x):
    v = 0
    for i in range(B-1,-1,-1):
        b = (x >> i) & 1
        if not filho[v][b]:
            filho[v][b] = len(filho)
            filho.append([0, 0])
        v = filho[v][b]

def melhor(x):
    v, r = 0,0
    for i in range(B -1, -1, -1):
        b = (x >> i) & 1
        if filho[v][b ^1]:
            r |= 1 << i
            v = filho[v][b ^ 1]
        else:
            v = filho[v][b]
    return r

t = int(input())
saida = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    reinicia()
    insere(a[0])
    r = 0
    for x in a[1:]:
        r = max(r, melhor(x))
        insere(x)
    saida.append(r)
print('\n'.join(map(str, saida)))