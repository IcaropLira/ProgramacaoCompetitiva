def main():
    N, Q = map(int, input().split())
    
    total = N

    dentes = [int(i) for i in input().split()]
    tratados = set()

    for i in range(Q):
        if dentes[i] <= N and dentes[i] not in tratados:
            total -= 1
            tratados.add(dentes[i]) 
        else:
            total += 1
            tratados.remove(dentes[i])
    print(total)      

main()