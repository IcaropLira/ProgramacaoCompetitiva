N, K = map(int, input().split())

A = [0] * N

def dfs(i, restante):
    if i == N:
        if restante % N == 0:
            A[N - 1] = restante // N
            print(*A)
        return

    for x in range(restante // i + 1):
        A[i - 1] = x
        dfs(i + 1, restante - i * x)


dfs(1, K)