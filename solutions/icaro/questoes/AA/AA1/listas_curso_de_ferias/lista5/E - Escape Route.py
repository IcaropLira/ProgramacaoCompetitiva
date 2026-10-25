H, W = map(int, input().split())
grid = [list(input()) for _ in range(H)]


fila_x = []
fila_y = []


for i in range(H):
    for j in range(W):
        if grid[i][j] == 'E':
            fila_x.append(i)
            fila_y.append(j)

head = 0

while head < len(fila_x):
    x = fila_x[head]
    y = fila_y[head]
    head += 1
    

    if x > 0 and grid[x-1][y] == '.':
        grid[x-1][y] = 'v'
        fila_x.append(x-1)
        fila_y.append(y)
    

    if x < H-1 and grid[x+1][y] == '.':
        grid[x+1][y] = '^'
        fila_x.append(x+1)
        fila_y.append(y)
    

    if y > 0 and grid[x][y-1] == '.':
        grid[x][y-1] = '>'
        fila_x.append(x)
        fila_y.append(y-1)
    

    if y < W-1 and grid[x][y+1] == '.':
        grid[x][y+1] = '<'
        fila_x.append(x)
        fila_y.append(y+1)


for i in range(H):
    print(''.join(grid[i]))