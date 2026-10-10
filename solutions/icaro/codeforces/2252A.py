t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    freq = {}

    for x in a:
        if x in freq:
            freq[x] += 1
        else:
            freq[x] = 1

    total = sum(a)

    mx = 0
    valor = 0

    for x in freq:
        if freq[x] > mx:
            mx = freq[x]
            valor = x

    outros = n - mx

    if mx <= outros + 1:
        print(total)
    else:
        perdidas = mx - (outros + 2)
        print(total - perdidas * valor)