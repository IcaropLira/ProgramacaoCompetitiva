import bisect

N, Q = map(int, input().split())
A = list(map(int, input().split()))

A.sort()

prefix = [0] * (N + 1)
for i in range(N):
    prefix[i+1] = prefix[i] + A[i]

total = prefix[N]

for _ in range(Q):
    b = int(input())
    
    pos = bisect.bisect_left(A, b)
    
    soma1 = prefix[pos]
    soma2 = (N - pos) * (b - 1)
    
    S = soma1 + soma2
    
    if S + 1 > total:
        print(-1)
    else:
        print(S + 1)