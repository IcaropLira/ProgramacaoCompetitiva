nums = list(map(int, input().split()))
nums.sort()
dist = []
for i in range(2):
    dist.append(abs(nums[i] - nums[i+1]))
print(sum(dist))
