n = int(input())
nums = list(map(int, input().split()))

c = 1
maiorc = 1 

for i in range(n - 1):
    if nums[i] <= nums[i + 1]:
        c += 1
    else:
        c = 1
    if c > maiorc:
        maiorc = c

print(maiorc)