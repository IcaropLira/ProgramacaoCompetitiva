n = int(input())
nums = list(map(int, input().split()))
nums.sort(reverse=True)
c = 0
tot = 0
for i in nums:
    if tot >= n: break
    tot += i
    c +=1
if tot >= n:
    print(c)
else: 
    print(-1)