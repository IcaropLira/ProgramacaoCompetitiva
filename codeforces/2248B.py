import sys
input = sys.stdin.readline

def main():
    t = int(input())
    out = []
    for _ in range(t):
        n, m = map(int, input().split())
        a = sorted(map(int, input().split()))
        b = sorted(map(int, input().split()))

        if n < 2 * m:
            out.append("NO")
            continue

        ok = True
        for i in range(m):
            if not (a[i] < b[i] and a[n - m + i] > b[i]):
                ok = False
                break

        out.append("YES" if ok else "NO")
    print("\n".join(out))

main()