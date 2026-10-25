def main():
    K, G, M = map(int, input().split())

    copo = 0
    caneca = 0

    for _ in range(K):
        if copo == G:
            copo = 0
        elif caneca == 0:
            caneca = M
        else:
            transferir = min(caneca, G - copo)
            copo += transferir
            caneca -= transferir

    print(copo, caneca)


main()