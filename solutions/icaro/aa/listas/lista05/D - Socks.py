N = int(input())
meias = list(map(int, input().split()))
conjunto = {}
pares = 0
for i in range(N):
    conjunto[meias[i]] = conjunto.get(meias[i], 0 ) + 1
    if conjunto[meias[i]] % 2 == 0 and conjunto[meias[i]] != 0 :
        pares += 1
print(pares)