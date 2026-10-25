qnts = int(input())

for _ in range(qnts):
    a, b = map(int, input().split())
    
    if a == b:
        print(0)
        continue
    maior = max(a, b)
    menor = min(a, b)
    if maior % menor != 0:
        print(-1)
        continue

    razao = maior // menor

    if razao & (razao - 1):
        print(-1)
        continue

    c = 0

    for i in [8, 4, 2]:
        while razao % i == 0:
            razao //= i
            c += 1
    print(c)

