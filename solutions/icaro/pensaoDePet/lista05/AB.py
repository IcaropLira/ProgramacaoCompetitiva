n = int(input())
for i in range(n):
    m = int(input())
    nums = set(list(map(int, input().split())))
    if 67 in nums:
        print("YES")
    else: 
        print("NO")