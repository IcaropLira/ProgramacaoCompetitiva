def union(a, b, pais):
    raiz_a = find(a, pais)
    raiz_b = find(b, pais)

    if raiz_a == raiz_b:
        return False

    if pais[raiz_b] < pais[raiz_a]:
        raiz_a, raiz_b = raiz_b, raiz_a
    
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

for _ in range(m):
    entrada = list(map(int, input().split()))

    for i in range(1, entrada[0]):
        union(entrada[i], entrada[i+1], pais)

rep = [0] * (n+1)

for i in range(1, n+1):
    rep[i] = find(i, pais)

freq = {}

for i in range(1, n+1):
    freq[rep[i]] = freq.get(rep[i], 0) + 1

res = []

for i in range(1, n+1):
    res.append(freq[rep[i]])

print(*res)