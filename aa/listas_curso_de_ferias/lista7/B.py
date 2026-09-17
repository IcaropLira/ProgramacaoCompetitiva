H = int(input())

altura = 0
crescimento = 1
dia = 0

while altura <= H:
    altura += crescimento
    crescimento *= 2
    dia += 1

print(dia)