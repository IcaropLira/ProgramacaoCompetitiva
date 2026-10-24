import math
quantidade_bolas = int(input())

cores = list(map(int, input().split()))

dp = [[0] * quantidade_bolas for _ in range(quantidade_bolas)]

for i in range(quantidade_bolas):
    dp[i][i] = 1

for tamanho in range(2, quantidade_bolas + 1):
    for inicio in range(quantidade_bolas - tamanho + 1):
        fim = inicio + tamanho - 1

        menor_custo = math.inf
        for corte in range(inicio, fim):
            custo_atual = dp[inicio][corte] + dp[corte + 1][fim]
            if custo_atual < menor_custo:
                menor_custo = custo_atual

        if cores[inicio] == cores[fim]:

            if inicio + 1 <= fim - 1:
                custo_miolo = dp[inicio + 1][fim - 1]
            else:
                custo_miolo = 0

            if custo_miolo < menor_custo:
                menor_custo = custo_miolo

        dp[inicio][fim] = menor_custo

print(dp[0][quantidade_bolas - 1])