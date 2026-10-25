n = int(input())
nums = [0] + list(map(int, input().split()))

for i in range(1, n + 1):
    if nums[i] != i and nums[nums[nums[i]]] == i:
        print("YES")
        break
else:
    print("NO")