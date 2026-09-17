entrada = input().split()
H = int(entrada[0])
W = int(entrada[1])

entrada = input().split()
i = int(entrada[0])
j = int(entrada[1])
i -= 1
j -= 1

grid = []
for _ in range(H):
    linha = input().strip()
    grid.append(linha)

X = input().strip()

for move in X:
    
    ni = i
    nj = j
    
    if move == 'L':
        nj = j - 1
    elif move == 'R':
        nj = j + 1
    elif move == 'U':
        ni = i - 1
    elif move == 'D':
        ni = i + 1
    
    if 0 <= ni and ni < H and 0 <= nj and nj < W:
        if grid[ni][nj] == '.':
            i = ni
            j = nj  

print(i + 1, j + 1)