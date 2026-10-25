def main():
    n, m = map(int, input().split())
    grid = [list(input()) for _ in range(n)]

    visitado = [[False]*m for _ in range(n)]

    def bfs(i, j):
        fila = [(i, j)]
        visitado[i][j] = True
        head = 0
        
        while head < len(fila):
            x, y = fila[head]
            head += 1
            
            for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < n and 0 <= ny < m:
                    if grid[nx][ny] == '.' and not visitado[nx][ny]:
                        visitado[nx][ny] = True
                        fila.append((nx, ny))

    resposta = 0

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.' and not visitado[i][j]:
                bfs(i, j)
                resposta += 1

    print(resposta)


main()