import sys
input = sys.stdin.readline

def bfs(raiz):
    pai = [0] * (n+1)
    ordem = [raiz]
    for u in ordem:
        for ch in adj[u]:
            if ch != pai[u]:
                pai[ch] = u
                ordem.append(ch)
    return pai, ordem

def dfs(raiz):
    pai, ordem = bfs(raiz)
    for u in reversed(ordem):
        for ch in adj[u]:
            if ch != pai[u]:
                if len(colors[ch]) > len(colors[u]):
                    color[ch], color[u] = color[u], color[ch]
        colors[u].add(color[u])

        for ch in adj[u]:
            if ch != pai[u]:
                for c in colors[ch]:
                    colors[ch].add(c)
                colors[ch].clear()
        ans[u] = len(colors[u])

n = int(input())

color = [0] + list(map(int, input().split()))

adj = [[] for i in range(n+1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
colors = [set() for _ in range(n+1)]

ans = [0] * (n+1)
dfs(1)
print(*ans[1:])        