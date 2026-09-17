N, K = map(int, input().split())
A = list(map(int, input().split()))

contagem = [0] * K

for x in A:
    contagem[x - 1] += 1

maior = max(contagem)

resposta = 0

for x in contagem:
    if x == maior or x == maior - 1:
        resposta += 1

print(resposta)