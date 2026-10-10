N = int(input())

f = [0] * (3 * N + 10)

ultimo = 0

for n in range(1, N + 1):

    if f[n] == 0:
        f[n] = max(n + 1, ultimo + 1)
    x = f[n]

    f[x] = 3 * n

    ultimo = x

print(f[N])