n,m = list(map(int, input().split()))

lista = []
for _ in range(m):
    a, b = list(map(int, input().split()))
    lista.append((a, b))

morreu = False    
lista.sort()
for e in lista:
    if n > e[0]:
        n += e[1]
    else:
        morreu = True
        break
    
if morreu:
    print("NO")
else: print("YES")