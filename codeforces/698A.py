n = int(input())
a = list(map(int, input().split()))

dp = [[float("inf")] * 3 for i in range(n)]

dp[0][0] = 1
if a[0] == 1 or a[0] == 3:
    dp[0][1] = 0
if a[0] == 2 or  a[0] == 3:
    dp[0][1] = 0

for i in range(1, n):
    dp[i][0] = min(dp[i-1])