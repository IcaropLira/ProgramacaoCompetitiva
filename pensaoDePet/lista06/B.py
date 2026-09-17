n, k = map(int, input().split())
h = list(map(int, input().split()))

dp = [0] * (n + 1)

for i in range(n):
    dp[i + 1] = dp[i] + h[i]

menor = float('inf')
resposta = 1

for i in range(n - k + 1):
    soma = dp[i + k] - dp[i]

    if soma < menor:
        menor = soma
        resposta = i + 1  

print(resposta)