import sys

def main():
    N, Q = map(int, sys.stdin.readline().split())
    nums = list(map(int, sys.stdin.readline().split()))

    pref = [0]
    for num in nums:
        pref.append(pref[-1] + num)

    res = []
    for _ in range(Q):
        a, b = map(int, sys.stdin.readline().split())
        res.append(str(pref[b] - pref[a-1]))

    print("\n".join(res))

main()