def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a, b, pais):
    raiz_a = find(a, pais)
    raiz_b = find(b, pais)
    if raiz_a == raiz_b:
        return False
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return True

pilhas = [[]]
n = int(input())
pais = [-1] * (n+1)
for i in range(n):
    a, b = map(int, input().split())
    pilhas.append((a,b))
for i in range(1, n+1):
    for j in range(i, n+1):
        if pilhas[i][0] == pilhas[j][0] or pilhas[i][1] == pilhas[j][1]:
            union(i, j, pais)

res = []

for i in range(1,n+1):
    res.append(find(i, pais))
resfin = len(set(res)) -1
print(resfin)