#CSES 1666

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

n, m = map(int, input().split())
pais = [-1] * (n+1)

for i in range(m):
    a, b = map(int, input().split())
    union(a, b, pais)

rep = [0] * (n+1)

for i in range(1, n+1):
    rep[i] = find(i, pais)

res = (set(rep[1:]))
res1 = list(res)

print(len(res) -1)

for i in range(len(res)-1):
    print(res1[i], res1[i+1])