import sys
input = sys.stdin.readline

n, target = map(int, input().split())

nums = list(map(int, input().split()))
conjunto = {}
tem = False

for i in range(n):
    complemento = target - nums[i]
    if complemento in conjunto:
        print(conjunto[complemento] +1, i +1)
        tem = True
        break
    conjunto[nums[i]] = i

if not tem:
    print("IMPOSSIBLE")