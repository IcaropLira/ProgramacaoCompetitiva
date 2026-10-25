n, m = map(int, input().split())
grid = [input() for _ in range(n)]

visitado = [[False]*m for _ in range(n)]

def bfs(i, j):
    fila_x = [i]
    fila_y = [j]
    visitado[i][j] = True
    
    head = 0
    
    while head < len(fila_x):
        x = fila_x[head]
        y = fila_y[head]
        head += 1
        
        if x > 0:
            if grid[x-1][y] == '.' and not visitado[x-1][y]:
                visitado[x-1][y] = True
                fila_x.append(x-1)
                fila_y.append(y)
        
        if x < n-1:
            if grid[x+1][y] == '.' and not visitado[x+1][y]:
                visitado[x+1][y] = True
                fila_x.append(x+1)
                fila_y.append(y)
        
        if y > 0:
            if grid[x][y-1] == '.' and not visitado[x][y-1]:
                visitado[x][y-1] = True
                fila_x.append(x)
                fila_y.append(y-1)
        
        # direita
        if y < m-1:
            if grid[x][y+1] == '.' and not visitado[x][y+1]:
                visitado[x][y+1] = True
                fila_x.append(x)
                fila_y.append(y+1)

resposta = 0

for i in range(n):
    for j in range(m):
        if grid[i][j] == '.' and not visitado[i][j]:
            bfs(i, j)
            resposta += 1

print(resposta)