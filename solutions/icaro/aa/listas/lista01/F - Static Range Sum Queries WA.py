def main():
    N, Q = map(int, input().split())

    nums = [int(i) for i in input().split()]
    pref = []
    x = 0
    for i in range(N):
        x += nums[i]
        pref.append(x)

    for i in range(Q):
        idx1, idx2 = map(int, input().split())
        if idx1 == 1 and idx2== len(nums):
            print(pref[-1])
        else:
            print(pref[idx2-1] - pref[idx1 -2])

main()