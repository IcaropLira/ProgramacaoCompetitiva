N, Q = map(int, input().split())
A = list(map(int, input().split()))

pref = [0] * N
pref[0] = A[0]
for i in range(1, N):
    pref[i] = pref[i-1] + A[i]

shift = 0

for _ in range(Q):
    query = list(map(int, input().split()))
    
    if query[0] == 1:
        c = query[1]
        shift = (shift + c) % N
    
    else:
        l, r = query[1], query[2]
        
        l -= 1
        r -= 1
        
        real_l = (shift + l) % N
        real_r = (shift + r) % N
        
        if real_l <= real_r:
            res = pref[real_r] - (pref[real_l - 1] if real_l > 0 else 0)
        else:
            res = (pref[N-1] - (pref[real_l - 1] if real_l > 0 else 0)) + pref[real_r]
        
        print(res)