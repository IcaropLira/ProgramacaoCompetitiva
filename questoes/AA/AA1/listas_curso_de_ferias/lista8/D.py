import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a != b:
            self.parent[b] = a


def main():
    N = int(input())
    edges = []
    floors = set()

    for _ in range(N):
        a, b = map(int, input().split())
        edges.append((a, b))
        floors.add(a)
        floors.add(b)

    # garantir que o andar 1 está incluído
    floors.add(1)

    # compressão
    floors = list(floors)
    comp = {v: i for i, v in enumerate(floors)}

    uf = UnionFind(len(floors))

    # unir
    for a, b in edges:
        uf.union(comp[a], comp[b])

    root_1 = uf.find(comp[1])

    # procurar maior andar conectado ao 1
    ans = 1
    for f in floors:
        if uf.find(comp[f]) == root_1:
            ans = max(ans, f)

    print(ans)


if __name__ == "__main__":
    main()