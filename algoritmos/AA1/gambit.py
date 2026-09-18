import math
p = int(input())

mdc = math.gcd(p,100)
resposta = 100//mdc
print(resposta)