n = int(input())
nums = list(map(int, input().split()))
nums.sort()

L = 0
ans = 0

for R in range(n):

    while nums[R] - nums[L] > 5:
        L += 1

    ans = max(ans, R - L + 1)

print(ans)