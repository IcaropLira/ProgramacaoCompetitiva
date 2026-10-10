N = int(input())
numeros = list(map(int, input().split()))

pilha = []  
total_elementos = 0

for x in numeros:
    if pilha and pilha[-1][0] == x:
        pilha[-1][1] += 1
    else:
        pilha.append([x, 1])
    
    total_elementos += 1

    valor_topo, contador_topo = pilha[-1]
    if contador_topo == valor_topo:
        pilha.pop()
        total_elementos -= valor_topo

    print(total_elementos)