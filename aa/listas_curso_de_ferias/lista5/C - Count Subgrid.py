def main():
    N, M = map(int, input().split())
    grid = [input().strip() for _ in range(N)]

    padroes = set()

    for i in range(N - M + 1):
        for j in range(N - M + 1):
            
            bloco = []
            
            for x in range(M):
                linha = grid[i + x][j:j + M]
                bloco.append(linha)
            
            padrao = "".join(bloco)
            
            padroes.add(padrao)

    print(len(padroes))

main()