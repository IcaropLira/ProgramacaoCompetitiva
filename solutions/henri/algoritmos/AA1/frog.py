num = int(input())

for _ in range(num):
    n,a,b = map(int, input().split())
    
    if (abs(a-b) + 1) % 2 == 0:
        print("NO")
    else:
        print("YES")