import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n  # para otimizar união

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)

        if a != b:
            # une o menor no maior
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.parent[b] = a
            self.size[a] += self.size[b]

    def connected(self, a, b):
        return self.find(a) == self.find(b)


def main():
    N, Q = map(int, input().split())
    uf = UnionFind(N)

    for _ in range(Q):
        P, A, B = map(int, input().split())

        if P == 0:
            uf.union(A, B)
        else:
            print("Yes" if uf.connected(A, B) else "No")


if __name__ == "__main__":
    main()