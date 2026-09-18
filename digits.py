import sys
sys.setrecursionlimit(10**6)

def nsei(n, contador):
    if n == 0:
        return contador
    contador += 1
    return nsei(n-int(max((list(str(n))))), contador)
    
n = int(input())

print(nsei(n,0))