import math
import sys

def crivo(n):
    primos = [True] * (n+1)
    saida = []
    if n >= 0:
        primos[0] = False
        saida.append(0)
    if n >= 1:
        primos[1] = False
        saida.append(0)
    p = 2
    while p * p <= n:
        if primos[p]:
            multiplo = p * p
            while multiplo <= n:
                primos[multiplo] = False
                saida.append(multiplo)
                multiplo += p
        p += 1
    return saida

def nseioq(n):
    
    lista = crivo(n)
    return lista
    
    
n = int(sys.stdin.readline())
print(sorted(nseioq(n)))

                    