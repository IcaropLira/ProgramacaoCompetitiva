n = int(input())
dp = [float("inf")] * (n+1)
dp[0] = 0
for i in range(1, n + 1):
    for d in str(i):
        d = int(d)
        if d != 0:
            dp[i] = min(dp[i], dp[i - d] + 1)
print(dp[-1])

