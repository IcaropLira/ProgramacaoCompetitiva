import sys

def solve():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] ^ int(data[i + 1])

    res = 0
    mask = 0
    for i in range(30, -1, -1):
        mask |= 1 << i
        prefixos = {p & mask for p in pre}
        cand = res | (1 << i)
        if prefixos & {cand ^ p for p in prefixos}:
            res = cand

    print(res)

solve()