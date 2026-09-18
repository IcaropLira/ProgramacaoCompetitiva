import math
m, n = map(int, input().split())

a = m-1
b = n-1

saida = math.factorial(a + b)/ (math.factorial(a)*math.factorial(b))

print(int(saida))