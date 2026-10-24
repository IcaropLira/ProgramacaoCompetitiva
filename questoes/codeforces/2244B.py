t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    precisa = 1

    ok = True
    for i in range(n):
        if a[i] < precisa:
            ok = False
            break

        sobra = a[i] - precisa
        if i + 1 < n:
            a[i + 1] += sobra

        precisa += 1

    print("YES" if ok else "NO")