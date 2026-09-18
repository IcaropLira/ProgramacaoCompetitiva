import sys
def sein(n):
    contador = 0
    p = 1
    while p * p <= n:
        if n % p == 0:
            if p * p == n:
                contador += 1
            else:
                contador += 2
        p += 1
    return contador
        

n = int(sys.stdin.readline())

for _ in range(n):
    num = int(sys.stdin.readline())
    print(sein(num))
    