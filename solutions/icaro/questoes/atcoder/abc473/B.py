n = int(input())
nums = list(map(int, input().split()))

contagem = {}

for x in nums:
    contagem[x] = contagem.get(x, 0) + 1

resposta = 0

for x in contagem:
    if contagem[x] % 2 == 1:
        resposta += x

print(resposta)