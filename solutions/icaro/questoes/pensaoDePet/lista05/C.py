n = int(input())
nums = list(map(int, input().split()))

nums.sort(reverse=True)

total = sum(nums)
peguei = 0

for i in range(n):
    peguei += nums[i]
    if peguei > total - peguei:
        print(i + 1)
        break