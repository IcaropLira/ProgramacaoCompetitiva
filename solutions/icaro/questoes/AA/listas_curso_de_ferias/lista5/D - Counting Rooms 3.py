n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]

def bfs(i, j):
    fila_x = [i]
    fila_y = [j]
    grid[i][j] = '#'  
    
    head = 0
    
    while head < len(fila_x):
        x = fila_x[head]
        y = fila_y[head]
        head += 1
        
        if x > 0 and grid[x-1][y] == '.':
            grid[x-1][y] = '#'
            fila_x.append(x-1)
            fila_y.append(y)
        
        if x < n-1 and grid[x+1][y] == '.':
            grid[x+1][y] = '#'
            fila_x.append(x+1)
            fila_y.append(y)
        
        if y > 0 and grid[x][y-1] == '.':
            grid[x][y-1] = '#'
            fila_x.append(x)
            fila_y.append(y-1)
        
        if y < m-1 and grid[x][y+1] == '.':
            grid[x][y+1] = '#'
            fila_x.append(x)
            fila_y.append(y+1)

resposta = 0

for i in range(n):
    for j in range(m):
        if grid[i][j] == '.':
            bfs(i, j)
            resposta += 1

print(resposta)