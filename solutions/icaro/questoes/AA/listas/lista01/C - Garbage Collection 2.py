def main():
    N = int(input())
    
    coletas = []
    for _ in range(N):
        coletas.append([int(i) for i in input().split()])
    
    Q = int(input())
    for _ in range(Q):
        tipo, dia = map(int, input().split())

        prox = dia + (coletas[tipo -1][1] - (dia % coletas[tipo -1][0])) % coletas[tipo -1][0]
        print(prox)
main()