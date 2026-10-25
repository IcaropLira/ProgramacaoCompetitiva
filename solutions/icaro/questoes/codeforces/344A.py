n = int(input())

ant = input()
grupos = 1

for _ in range(n - 1):
    atual = input()
    if atual != ant:
        grupos += 1
    ant = atual

print(grupos)