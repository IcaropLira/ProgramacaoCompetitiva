def main():
    n = int(input())
    P = list(map(int, input().split()))
    
    pos = [0] * (n + 1)
    
    for i in range(n):
        pos[P[i]] = i  
    q = int(input())
    
    for _ in range(q):
        a, b = map(int, input().split())
        
        if pos[a] < pos[b]:
            print(a)
        else:
            print(b)

main()