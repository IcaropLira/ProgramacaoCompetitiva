n = int(input())
m = int(input())
arm = []
for i in range(n):
    arm.append(int(input()))
tot = 0
c =0
arm.sort(reverse=True)
for i in arm:
    if tot  >= m:
        break
    tot += i
    c+= 1
print(c)