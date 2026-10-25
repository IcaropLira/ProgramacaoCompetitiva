n, t1, t2, t3 = map(int, input().split())
tam = [t1, t2, t3]
tam.sort()
dp =  [0] * (n+1)
dp[0] = 0

for i in range(1, n+1):
    temp = []
    if i < tam[0]:
        dp[i] = -1
    else:
        for j in tam:
            if i - j >= 0 and dp[i-j] > -1:
                temp.append(dp[i- j])
        if temp:
            dp[i] = max(temp) +1
        else: 
            dp[i] = -1

print(dp[-1])