n = int(input())
nums = list(map(int, input().split()))
lim = 1000* 1000


sortado = sorted(nums[::])
nums1 = nums[::]
c = 0
while nums != nums.sort():
    for i in range(2*n-1):
        nums[i+1], nums[i] = nums[i+1], nums[i]
    c+=1
    if c > lim: break

d = 0
while nums1 != nums.sort():
    for i in range(2*n-1):
        nums1[i+1], nums1[i] = nums1[i+1], nums1[i]
    d+=1
    if d > lim: break
if c > lim and d > lim:
    print(-1)
else:
    print(min(c,d))