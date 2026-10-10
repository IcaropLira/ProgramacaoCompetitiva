dp = [0] * 4001
dp[0] = 1

for i in range(4001):
    if dp[i]:
        if i + 11 <= 4000:
            dp[i + 11] = 1
        if i + 111 <= 4000:
            dp[i + 111] = 1

t = int(input())

for _ in range(t):
    n = int(input())

    if n > 1099:
        print("YES")
    else:
        print("YES" if dp[n] else "NO")