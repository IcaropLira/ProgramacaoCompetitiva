n = int(input())
soma = 0

xAnt, yAnt = map(int, input().split())
x0, y0 = xAnt, yAnt
for i in range(n-1):
    x, y = map(int, input().split())
    soma += y * xAnt - x * yAnt
    xAnt, yAnt = x, y

soma += y0 * xAnt - x0 * yAnt

saida = abs(soma) 
print(saida)