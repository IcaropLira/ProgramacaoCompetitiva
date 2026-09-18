n, m = list(map(int, input().split()))

lista = list(map(int, input().split()))

for i in range(len(lista)):
    if i == 0 and i+1 < len(lista) and lista[i+1] == 0 and lista[i] == 0:
        m -= 1
        lista[i] = 1
    if i == len(lista) -1 and lista[i-1] == 0 and lista[i] == 0:
        m -= 1
        lista[i] = 1
    elif i > 0 and i < len(lista) -1 and lista[i-1] == 0 and lista[i+1] == 0 and lista[i] == 0:
        m -= 1
        lista[i] = 1

if m <= 0:
    print(True)
else: print(False)