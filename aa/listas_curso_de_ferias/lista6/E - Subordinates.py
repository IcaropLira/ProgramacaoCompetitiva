import sys
sys.setrecursionlimit(10**7)

def main():

    n = int(input())
    chefes = list(map(int, input().split()))

    tree = [[] for _ in range(n+1)]

    for i in range(2, n+1):
        chefe = chefes[i-2]
        tree[chefe].append(i)

    res = [0]*(n+1)

    def dfs(u):
        total = 1
        for v in tree[u]:
            total += dfs(v)
        res[u] = total - 1
        return total

    dfs(1)

    print(*res[1:])



main()