INF = 10**6
n = int(input())
x = n

dp = [INF] * (n+1)
dp[0] = 0
for i in range(1, n+1):
    for d in str(i):
        dig = int(d)
        if dig != 0:
            dp[i] = min(dp[i], 1 + dp[i-dig])

print(dp)
print(dp[x])