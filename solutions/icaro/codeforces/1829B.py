t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    atual = 0
    maior = 0

    for x in a:
        if x == 0:
            atual += 1
        else:
            maior = max(maior, atual)
            atual = 0

    maior = max(maior, atual)

    print(maior)