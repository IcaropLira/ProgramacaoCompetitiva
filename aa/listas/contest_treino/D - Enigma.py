mensagem = input().strip()
crib = input().strip()

N = len(mensagem)
M = len(crib)

res = 0

for i in range(N - M + 1):
    valido = True
    for j in range(M):
        if mensagem[i + j] == crib[j]:
            valido = False
            break
    if valido:
        res += 1

print(res)