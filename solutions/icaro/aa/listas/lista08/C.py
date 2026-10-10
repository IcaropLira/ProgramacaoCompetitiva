def union(a, b, pais):
    raiz_a = find(a, pais)
    raiz_b = find(b, pais)

    if raiz_a == raiz_b:
        return False
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return True


def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]



n, m = map(int, input().split())

pais = [-1] * (n+1)

rep = [0] * (n+1)

quem_fala = {}

for i in range(1, m+1):
    quem_fala[i] = []
alguma_lingua = False
for i in range(1, n+1):
    entrada = list(map(int, input().split()))
    k = entrada[0]
    if k>0:
        alguma_lingua = True
    for j in range(1, k+1):
        quem_fala[entrada[j]].append(i)

for i in quem_fala:
   atual = quem_fala[i]
   for j in range(len(atual)-1):
       union(atual[j], atual[j+1], pais)

for i in range(1, n+1):
    rep[i] = find(i, pais)

if len(set(rep[1:])) == n and not alguma_lingua:
   print(len(set(rep[1:])))
else:
    res = len(set(rep[1:])) -1
    print(res)