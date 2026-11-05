m, n = map(int(input().split()))

processados = set()
grau = [0] * n+1

for _ in range(n):
    a, b = map(int, input().split())
