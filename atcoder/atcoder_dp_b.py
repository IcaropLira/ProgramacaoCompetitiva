n, k = map(int, (input().split()))
h = list(map(int, input().split()))

dp = [0] * n

dp[0] = 0

for i in range(1, n):
    menor = float("inf")
    for j in range(1, k+1):
        if i-j < 0:
            break

        menor = min(
            menor,
            dp[i-j] + abs(h[i] - h[i-j])
        )
    dp[i] = menor
    
print(dp[-1])