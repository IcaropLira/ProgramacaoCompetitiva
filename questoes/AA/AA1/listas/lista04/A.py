from collections import deque

N, M = map(int, input().split())

fila = deque()
c = 0
for i in input().split():
    fila.append([c + 1, int(i)])
    c += 1

while len(fila) > 1:
    if fila[0][1] <= M:
        fila.popleft()
    else:
        individuo = fila.popleft()
        individuo[1] -= M
        fila.append(individuo)
print(fila[0][0])