n = int(input())

if n % 2 ==0:
    res = n//2
    print(res)
    nums = [2]* res
    print(*nums)
else: 
    num = n-1
    res = num//2
    print(res)
    nums =  [3] + [2] * (res-1)
    print(*nums)