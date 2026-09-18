entrada = list(map(int, input().split()))

nums = [0] + entrada
n = len(entrada)

dp = [0] * (n+1)

if n>=1:
    dp[1] = nums[1]

for k in range(2, n +1):
    dp[k] = max(dp[k-1], dp[k-2] + nums[k])
    
print(dp[n])