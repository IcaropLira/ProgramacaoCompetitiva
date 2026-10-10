m, n = map(int, input().split())

dp = []

for i in range(m):
    dp.append([0]* n)
dp[0][0] = 1

for i in range(len(dp)):
    for j in range(len(dp[i])):
        if 0 < i:
            dp[i][j] += dp[i-1][j]
        if 0 < j:
            dp[i][j] += dp[i][j-1]
        
print(dp[-1][-1])