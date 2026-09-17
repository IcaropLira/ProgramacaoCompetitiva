import sys

c = 1

while True:
    N, Q = map(int, sys.stdin.readline().split())
    if N == 0 and Q == 0: break
    nums = []
    for _ in range(N):
        nums.append(int(sys.stdin.readline()))
    
    nums.sort()
    
    sys.stdout.write(f"CASE# {c}:\n")
    for _ in range(Q):
        num = int(sys.stdin.readline())
        if num in nums:
            sys.stdout.write(f"{num} found at {nums.index(num) + 1}\n")
        else:
            sys.stdout.write(f"{num} not found\n")
    c += 1