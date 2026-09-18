import sys
sys.setrecursionlimit(2000000)

def meu_pow(a, b):
    if b == 0:
        return 1
    if b % 2 == 0:
        metade = meu_pow(a, b/2)
        return metade * metade
    outro = meu_pow(a, b-1)
    return a * outro

n = int(sys.stdin.readline().rstrip())
modulo = meu_pow(10, 9) + 7

for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    
    print(int(meu_pow(a,b) % modulo))
    

