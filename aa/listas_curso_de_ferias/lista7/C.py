N, X, Y = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

pratos = list(zip(A, B))

pratos_A = sorted(pratos, key=lambda x: -x[0])

somaA = somaB = 0
resp1 = N

for i, (a, b) in enumerate(pratos_A):
    somaA += a
    somaB += b
    if somaA > X or somaB > Y:
        resp1 = i + 1
        break

pratos_B = sorted(pratos, key=lambda x: -x[1])

somaA = somaB = 0
resp2 = N

for i, (a, b) in enumerate(pratos_B):
    somaA += a
    somaB += b
    if somaA > X or somaB > Y:
        resp2 = i + 1
        break

print(min(resp1, resp2))