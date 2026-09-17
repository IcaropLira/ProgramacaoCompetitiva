def main():
    q = int(input())
    fila = []
    inicio = 0
    
    for _ in range(q):
        entrada = input().split()
        
        if entrada[0] == "1":
            fila.append(int(entrada[1]))
        else:
            print(fila[inicio])
            inicio += 1

main()