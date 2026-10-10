N, T = map(int, input().split())
tempos = list(map(int, input().split()))

esquerda = 0
soma = 0
max_livros = 0

for direita in range(N):
    soma += tempos[direita]
    
    while soma > T:
        soma -= tempos[esquerda]
        esquerda += 1
    
    max_livros = max(max_livros, direita - esquerda + 1)

print(max_livros)