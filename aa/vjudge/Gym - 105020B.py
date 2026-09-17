import bisect

N = int(input())
clientes = map(int, input().split())

c = 0
tempos = [0]
for i in clientes:
    c+= i
    tempos.append(c)

total = tempos[-1]
Q = int(input())

for i in range(Q):
    X, Y, M = map(int, input().split())
    delivery = tempos[M] + Y
    
    k = bisect.bisect_left(tempos, X) - 1
    inicio = max(X, tempos[k])
    tempo_inicio_real = max(X, tempos[k])
    loja = inicio + (tempos[N] - tempos[k])

    print(min(loja, delivery))