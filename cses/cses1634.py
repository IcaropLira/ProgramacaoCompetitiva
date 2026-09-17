m, n = map(int, input().split())
moedas = list(map(int, input().split()))

moedas.sort()

INF = 10**9
dp = [INF] * (n + 1)

dp[0] = 0

for i in range(1, n + 1):
    for moeda in moedas:
        if moeda > i:
            break
        if dp[i - moeda] + 1 < dp[i]:
            dp[i] = dp[i - moeda] + 1
            
if dp[n] == INF:
    print(-1)
else:
    print(dp[n])