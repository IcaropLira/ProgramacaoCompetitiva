
n = int(input())
nums = list(map(int, input().split()))

ans = 0

for i in range(n - 2, -1, -1):
    if nums[i] >= nums[i+1]:
        ans = i + 1
        break 
print(ans)