n, m = map(int, input().split())

matriz = [input() for _ in range(n)]

def espelhar(matriz):
    return [linha[::-1] for linha in matriz]

def rodar(matriz):
    return ["".join(matriz[n - 1 - i][j] for i in range(n))for j in range(m)]

total = 0
atual = matriz

if n != m:
    for _ in range(2):
        if atual == matriz:
            total += 1
        if espelhar(atual) == matriz:
            total += 1
        atual = atual[::-1]

else:
    for _ in range(4):
        if atual == matriz:
            total += 1
        if espelhar(atual) == matriz:
            total += 1
        atual = rodar(atual)

print(total)