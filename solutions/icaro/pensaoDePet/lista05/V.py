from math import gcd

n = int(input())
nums = list(map(int, input().split()))

mdc = nums[0]
for x in nums:
    mdc = gcd(mdc, x)
c = 0
i = 1
while i * i <= mdc:
    if mdc % i == 0:
        c += 1 
        if i * i != mdc:
            c += 1
    i += 1

print(c)