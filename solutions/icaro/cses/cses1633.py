MOD = 10**9 + 7

n = int(input())
nums = [6, 5, 4, 3 ,2 ,1 ,0]
dp = [0] * (n+1)
dp[0] = 1
dp[1] = 1

for i in range(2, n+1):
    temp = []
    for j in nums:
        if i- j >= 0 and dp[i -j] != 0:
            temp.append(dp[i -j] % MOD) 
    dp[i] = sum(temp) % MOD
print(dp[-1])