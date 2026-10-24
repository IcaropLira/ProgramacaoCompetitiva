def main():
    N, M =  map(int, input().split())
    
    matriz = []
    for _ in range(N):
        matriz.append(input().strip())

    padroes = set()
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            subgrid = []
            for x in range(M):
                subgrid.append(matriz[i + x][j : j + M])
            padroes.add(str(subgrid))
    print(len(padroes))

main()