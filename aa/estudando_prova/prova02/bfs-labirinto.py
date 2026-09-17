from collections import deque

def bfs(i, j):
    fila = deque()
    fila.append((i,j, 0))  
    c = 0
    while fila:
        x, y, dist = fila.popleft()
        v[x][y] = 1
        if ma[x][y] == "E":
            return dist
        c+= 1
        if (x+1 < n) and (ma[x+1][y] =="." or  ma[x+1][y] =="E") and v[x+1][y] == 0:
            fila.append((x+1,y, dist+1))
            v[x+1][y] = 1
        if x-1 >=0 and( ma[x-1][y] =="." or  ma[x-1][y] =="E") and v[x-1][y] == 0:
            fila.append((x-1,y, dist +1))
            v[x-1][y] = 1
        if y-1 >=0 and (ma[x][y-1] =="." or  ma[x][y-1] =="E") and v[x][y-1] == 0:
            fila.append((x,y-1, dist+1))
            v[x][y-1] = 1
        if y+1 <m and( ma[x][y+1] =="." or  ma[x][y+1] =="E") and v[x][y+1] == 0:
            fila.append((x,y+1, dist+1))
            v[x][y+1] = 1
    return -1 
        

n, m = map(int, input().split())
ma = []
for i in range(n):
    ma.append(input())

v = [[0 for i in range(m)] for j in range(n)] 
for i in range(n):
    for j in range(m):
        if ma[i][j] == "S":
            caminho = bfs(i, j)
print(caminho)
