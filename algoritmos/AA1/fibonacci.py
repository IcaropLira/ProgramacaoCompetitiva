n = int(input())

a = 0
b = 1

lista = []
for _ in range(n):
    lista.append(a)
    a, b = b, a+b
    
print(*lista)