

n, m, k = map(int, input().split())

inf = float("inf")

lista = [[] for i in range(n+1)]
listaInversa = [[] for i in range(n+1)]

dp = [[inf, inf, 0] for i in range(n+1)]
dp[1][0] = dp[1][1] = 0

for _ in range(m):
    a, b, c, d = map(int, input().split())

    lista[a].append([b, c, d])
    listaInversa[b].append([a, c, d])

for i in range(2, len(listaInversa)):
    for r in listaInversa[i]:
        if dp[i] > dp[r[0]] + r[1]:
            dp[i] = dp[r[0]] + r[1]

print(dp[n])


