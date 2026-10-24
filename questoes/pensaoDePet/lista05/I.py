n, l = map(int, input().split())

lanternas = list(map(int, input().split()))
lanternas.sort()
dist = []
if lanternas[0] != 0:
    dist.append(lanternas[0])
if lanternas[-1] != l:
    dist.append(l - lanternas[-1])
for i in range(n-1):
    dist.append(abs(lanternas[i] - lanternas[i+1])/2)
print(f"{max(dist):.10f}")