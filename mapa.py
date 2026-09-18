def dfs(lista, i, j, visitados):
    visitados.add((i,j))
    if i + 1 < len(lista) and (i+1, j) not in visitados and lista[i + 1][j] == "H":
        return dfs(lista, i+1, j, visitados)
    elif i - 1 >= 0 and (i-1, j) not in visitados and lista[i - 1][j] == "H":
        return dfs(lista, i-1, j, visitados)
    elif j + 1 < len(lista[i]) and (i, j+1) not in visitados and lista[i][j+1] == "H":
        return dfs(lista, i, j+1, visitados)
    elif j - 1 >= 0 and (i, j-1) not in visitados and lista[i][j-1] == "H":
        return dfs(lista, i, j-1, visitados)
    else:
        return i, j
    


n, m = [int(e) for e in input().split()]

mapa = []
for _ in range(n):
    entrada = list(input())
    mapa.append(entrada)

for i in range(len(mapa)):
    for j in range(len(mapa[i])):
        if mapa[i][j] == "o":
            inicial = (i,j)

visitados = set()

a, b = dfs(mapa, inicial[0], inicial[1], visitados)
print(a+1, b+1)