# incopleta
n = int(input())

lista = []
for _ in range(n):
    a, b, c = map(int, input().split())
    linha = [a,b,c]
    linha.sort()
    lista.append(linha)

eh = False

for i in range(len(lista)):
    for j in range(len(lista)):
        soma = 0
        if lista[i][0] <= lista[j][0]:
            soma += 1
            if lista[i][1] <= lista[j][1]:
                soma += 1
                if lista[i][2] <= lista[j][2]:
                    soma += 1
            elif lista[i][1] <= lista[j][2]:
                soma += 1
                if lista[i][2] <= lista[j][1]:
                    soma += 1 
        elif lista[i][0] <= lista[j][1]:
            soma += 1
            if lista[i][1] <= lista[j][0]:
                soma += 1
                if lista[i][2] <= lista[j][2]:
                    soma += 1
            elif lista[i][1] <= lista[j][2]:
                soma += 1
                if lista[i][2] <= lista[j][0]:
                    soma += 1
        elif lista[i][0] <= lista[j][2]:
            soma += 1
            if lista[i][1] <= lista[j][0]:
                soma += 1
                if lista[i][2] <= lista[j][1]:
                    soma += 1
            elif lista[i][1] <= lista[j][1]:
                soma += 1
                if lista[i][2] <= lista[j][0]:
                    soma += 1         
        if soma < 2:
            eh = True
            break

if eh:
    print("Yes")
else:
    print("No")