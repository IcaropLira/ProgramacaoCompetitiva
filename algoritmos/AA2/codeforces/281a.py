linha = input()

linha = list(linha)

if not linha[0].isupper():
    linha[0].upper()

saida = ""
for e in linha:
    saida += e

print(saida)