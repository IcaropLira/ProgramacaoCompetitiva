n = int(input())
a = list(map(int, input().split()))

mx = max(a)
mn = min(a)

max_idx = a.index(mx)

for i in range(n - 1, -1, -1):
    if a[i] == mn:
        min_idx = i
        break

ans = max_idx + (n - 1 - min_idx)

if max_idx > min_idx:
    ans -= 1

print(ans)