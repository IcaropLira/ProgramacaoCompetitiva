n, w = map(int, input().split())

dp = []
for _ in range(n+1):
    dp.append([] * (w+1))
    for x in range(w+1):
        dp[_].append([0,0])
lista = []
for i in range(n):
    a , b = map(int, input().split())
    lista.append((a,b))
    if dp[i][w][0] + a <= w:
        dp[i+1][w][0] = a + dp[i][w][0]
        dp[i+1][w][1] = b + dp[i][w][1]
    else:
        seila = False
        for x in range(len(lista)):
            if lista[x][1] <= b and (dp[i][w][0] - lista[x][0]) + a <= w and (lista[x][1] < b or (lista[x][1] == b and lista[x][0] > a)):
                dp[i+1][w][0], a = dp[i][w][0] - lista[x][0] + a, lista[x][0]
                dp[i+1][w][1], b = dp[i][w][1] - lista[x][1] + b, lista[x][1]
                seila = True
        if not seila:
            dp[i+1][w][0] = dp[i][w][0]
            dp[i+1][w][1] = dp[i][w][1]
print(dp[n][w][1])
