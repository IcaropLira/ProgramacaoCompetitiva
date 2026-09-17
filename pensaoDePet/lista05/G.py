n, m = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
l = 0
menor = float("INF")
for i in range(m-n+1):
    menor = min(menor, abs(nums[l] -  nums[n+i -1]))
    l +=1
print(menor)
