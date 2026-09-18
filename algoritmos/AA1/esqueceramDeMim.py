import sys
input = sys.stdin.readline

k = int(input())

lista = list(map(int, input().split()))

lista.sort(reverse=True)
soma = 0
contador = 0
for e in lista:
    if soma >= k:
        break
    else:
        soma += e
        contador += 1

if soma < k:
    print(-1)
else:
    print(contador)