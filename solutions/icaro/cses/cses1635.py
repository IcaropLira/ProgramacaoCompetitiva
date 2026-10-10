MOD = 10**9 + 7

n, m = map(int, input().split())
moedas = list(map(int, input().split()))

dp = [0] * (m+1)

dp[0] = 1

for i in range(1, m+1):
    for moeda in moedas:
        if i >= moeda:
            dp[i] = (dp[i] + dp[i-moeda]) % MOD

print(dp[m])