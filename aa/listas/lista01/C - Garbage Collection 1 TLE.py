def main():
    N = int(input())
    
    coletas = []
    for _ in range(N):
        coletas.append([int(i) for i in input().split()])
    
    Q = int(input())
    for _ in range(Q):
        tipo, dia = map(int, input().split())
        prox = coletas[tipo -1][1]
        
        while True:
            if not prox < dia: break
            prox += coletas[tipo -1][0]
        print(prox)
        #deu TLE família
main()