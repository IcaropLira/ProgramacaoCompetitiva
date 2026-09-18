import sys
input = sys.stdin.readline
sys.setrecursionlimit(2*(10**6))
mod = 10**9 +7
n = int(input())
dp = []
for _ in range(n+1):
    dp.append(-1)
def contar_formas(soma):
    if soma == 0:
        return 1
    if soma < 0:
        return 0
    if dp[soma] != -1:
        return dp[soma]
    total = 0
    for dado in [1,2,3,4,5,6]:
        total = (total + contar_formas(soma-dado)) % mod
    dp[soma] = total
    return total
print(contar_formas(n))

