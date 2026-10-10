#o número de viagens que Raul planejou
#o número de viagens cobertas pelo bilhete de m 
# o preço de um bilhete de uma viagem 
# preço de um bilhete de m viagens.
n, m, a, b = map(int, input().split())

print(min(
    n * a,
    ((n + m - 1) // m) * b,
    (n // m) * b + (n % m) * a
))