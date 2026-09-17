import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)

        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.parent[b] = a
            self.size[a] += self.size[b]


def main():
    N, M = map(int, input().split())
    uf = UnionFind(N)

    for _ in range(M):
        A, B = map(int, input().split())
        A -= 1
        B -= 1
        uf.union(A, B)

    # contar tamanho das componentes
    comp_size = {}

    for i in range(N):
        root = uf.find(i)
        comp_size[root] = comp_size.get(root, 0) + 1

    print(max(comp_size.values()))


if __name__ == "__main__":
    main()