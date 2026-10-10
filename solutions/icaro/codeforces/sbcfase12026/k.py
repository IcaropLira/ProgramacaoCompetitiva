n = int(input())
c = list(map(int, input().split()))
k = list(map(int, input().split()))

total = sum(c)

ans = 0

for i in range(n):
    if c[i] < k[i]:
        print(-1)
        exit()

    ans = max(ans, total - c[i] + k[i])

print(ans)