import sys
import heapq

input = sys.stdin.readline

def solve():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        v = list(map(int, input().split()))
        
        if m == 1:
            print(1)
            for _ in range(n):
                _ = input()
            continue
        
        pieces = []
        for i in range(n):
            row = list(map(int, input().split()))
            for a in row:
                pieces.append((-a, i)) 
        
        heapq.heapify(pieces)
        
        stability = v[:]
        removed = 0
        
        while pieces:
            a, i = heapq.heappop(pieces)
            a = -a
            removed += 1
            for k in range(i+1):
                stability[k] -= a
                if stability[k] <= 0:
                    print(removed)
                    pieces.clear()
                    break

solve()