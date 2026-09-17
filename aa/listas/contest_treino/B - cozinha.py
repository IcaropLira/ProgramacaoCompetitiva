# qnt de ingredientes, n de pratos, pedidos a serem processados
#N inteiros separados por espaco, a qnt disponivel para o ingrediente i
#M descricoes de pratos, comeca com um linha contendo um n inteiro mi < N, quantos ingredientes diferentes sao necessarios para perparar o prato i 
#mi linhas, cada uma com dois inteiros separados por escao I ingrediente e Q quantidade do ingrediente
# cada uma das proximas O linhas descreve um pedido, que comeca com um inteiro O, iondicando o numero de pratos no pedido, uma lista oi numeros,
import sys


N, M, O = map(int, sys.stdin.readline().split())
estoque = list(map(int, sys.stdin.readline().split()))

pratos = []
for _ in range(M):
    mi = int(sys.stdin.readline())
    ingredientes = [tuple(map(int, sys.stdin.readline().split())) for _ in range(mi)]
    pratos.append(ingredientes)

res = 0

for _ in range(O):
    dados = list(map(int, sys.stdin.readline().split()))
    lista = dados[1:]
    
    usado = [0] * N
    
    for p in lista:
        for ing, qtd in pratos[p - 1]:
            usado[ing - 1] += qtd
    
    if any(usado[i] > estoque[i] for i in range(N)):
        break
    
    for i in range(N):
        estoque[i] -= usado[i]
    
    res += 1

print(res)