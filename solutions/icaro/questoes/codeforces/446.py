n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(1)
    exit()

L = [1] * n
for i in range(1, n):
    if a[i] > a[i - 1]:
        L[i] = L[i - 1] + 1

R = [1] * n
for i in range(n - 2, -1, -1):
    if a[i] < a[i + 1]:
        R[i] = R[i + 1] + 1

ans = max(L)

for i in range(n):
    if i > 0:
        ans = max(ans, min(n, L[i - 1] + 1))

    if i < n - 1:
        ans = max(ans, min(n, R[i + 1] + 1))

    if 0 < i < n - 1 and a[i - 1] + 1 < a[i + 1]:
        ans = max(ans, L[i - 1] + 1 + R[i + 1])

print(min(ans, n))