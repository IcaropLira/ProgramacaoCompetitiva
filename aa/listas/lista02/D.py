import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    possible = set()
    ans = float('inf')
    
    for x in a:
        new = {x}
        
        for val in possible:
            new.add(val & x)
        
        possible = new
        
        ans = min(ans, min(possible))
    
    print(ans)