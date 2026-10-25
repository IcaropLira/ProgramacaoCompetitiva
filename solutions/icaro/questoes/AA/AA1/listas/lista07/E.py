from collections import deque

def main():
    n = int(input())
    entrada1 = list(map(int, input().split()))
    fila1 = deque()
    for i in range(1, entrada1[0]+1):
        fila1.append(entrada1[i])
    entrada2 = list(map(int, input().split()))
    fila2 = deque()
    for i in range(1, entrada2[0]+1):
        fila2.append(entrada2[i])
    filas = set()
    c = 0
    while fila1 and fila2:
        jogada1 = fila1.popleft()
        jogada2 = fila2.popleft()
        if jogada1 > jogada2:
            fila1.append(min(jogada1, jogada2))
            fila1.append(max(jogada1, jogada2))
        else:
            fila2.append(min(jogada1, jogada2))
            fila2.append(max(jogada1, jogada2))
        c+= 1
        if tuple(fila1) in filas and tuple(fila2) in filas:
            print(-1)
            return
        filas.add(tuple(fila1))
        filas.add(tuple(fila2))
    if fila1:
        print(c, 1)
    else:
        print(c, 2)
main()