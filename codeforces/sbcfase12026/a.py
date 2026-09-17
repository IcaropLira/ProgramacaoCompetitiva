N = int(input())

compra = [0] * (N + 1)
venda = [0] * (N + 1)

for i in range(1, N + 1):
    c, v = map(int, input().split())

    compra[i] = compra[i - 1] + c
    venda[i] = venda[i - 1] + v

Q = int(input())

for _ in range(Q):
    n = int(input())

    if compra[n] > venda[n]:
        print("COMPRA")
    elif compra[n] < venda[n]:
        print("VENDA")
    else:
        print("NEUTRO")