import sys

N = int(sys.stdin.readline())


clientes = list(map(int,sys.stdin.readline().split()))

tempos = [0] * (N + 1)
for i in range(N):
    tempos[i+1] = tempos[i] + clientes[i]

total_fila_original = tempos[N]

Q = int(sys.stdin.readline())

resultados = []

for _ in range(Q):
    X, Y, M = map(int,sys.stdin.readline().split())
 
    delivery = tempos[M] + Y
    
    loja = max(X, total_fila_original)
    
    resultados.append(str(min(loja, delivery)))

sys.stdout.write("\n".join(resultados) + "\n")