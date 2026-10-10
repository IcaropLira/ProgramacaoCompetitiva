n = int(input())
jogos = n*(n-1)
casa = []
fora = {}
for i in range(n):
    a, b = map(int, input().split())
    casa.append(a)
    fora[b] = fora.get(b,0) + 1 
total = 0
for i in casa:
    total += fora.get(i,0)


print(total)