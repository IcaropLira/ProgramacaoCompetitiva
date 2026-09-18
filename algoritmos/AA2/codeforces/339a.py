lista = list(map(int, input().split("+")))

lista.sort()

saida = ""

for i in range(len(lista)):
    if i == 0:
        saida += str(lista[i])
    else:
        saida += "+" + str(lista[i])

print(saida)

