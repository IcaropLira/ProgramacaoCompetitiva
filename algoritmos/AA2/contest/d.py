n = int(input())

for i in range(n):
    linha = input()
    out = linha
    if linha[-1] == "s" and linha[-2] == "u":
        out = ""
        linha = list(linha)
        linha.pop(-1)
        linha[-1] = "i"
        for j in range(len(linha)):
            out += linha[j]
    print(out)

