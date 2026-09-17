t = int(input())
for _ in range(t):
    c = 0
    n, m = map(int, input().split())
    nums = sorted(list(map(int, input().split())))
    if n > 1:
        for i in range(n, -1, -1):
            if nums[i]+ nums[i-1] > m:
                c+= nums[i] + nums[i-1] - m
    print(c)
