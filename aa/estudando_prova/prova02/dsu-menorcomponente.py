def find(x, pais):
    if pais[x]< 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a, b, pais):
    ra = find(a, pais)
    rb = find(b, pais)
    if ra == rb:
        return False
    if pais[ra] > pais[rb]:
        ra, rb, = rb, ra
    pais[ra] += pais[rb]
    pais[rb] = ra
    return True

n, m = map(int, input().split())
pais = [-1] * (n+1)
for i in range(m):
    a, b = map(int, input().split())
    union(a,b, pais)


menor =  float("inf")
for i in range(1, n+1):
    if pais[i]< 0:
        menor = (min(menor, -pais[i]))
print(menor)
