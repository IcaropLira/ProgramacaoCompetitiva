import sys
import bisect

c = 1

while True:
    N, Q = map(int, sys.stdin.readline().split())
    if N == 0 and Q == 0: break
    
    nums = [int(sys.stdin.readline()) for _ in range(N)]
    nums.sort()
    
    sys.stdout.write(f"CASE# {c}:\n")
    
    for _ in range(Q):
        num = int(sys.stdin.readline())
        
        pos = bisect.bisect_left(nums, num)
        
        if pos < N and nums[pos] == num:
            sys.stdout.write(f"{num} found at {pos + 1}\n")
        else:
            sys.stdout.write(f"{num} not found\n")
    
    c += 1