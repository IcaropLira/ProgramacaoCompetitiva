n, m = map(int, input().split())
nums = list(map(int, input().split()))
c = 0
conj = set()
pos =  []
for i in range(n):
    if not nums[i] in conj:
        c+= 1
        pos.append(i+1)
        conj.add(nums[i])
        if len(pos) == m: break
if c>= m:
    print("YES")
    print(*pos)
else:
    print("NO")