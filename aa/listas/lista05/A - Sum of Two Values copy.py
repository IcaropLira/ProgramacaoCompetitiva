import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    target = int(data[1])
    nums = list(map(int, data[2:]))
    
    conjunto = {}
    
    for i in range(n):
        num_atual = nums[i]
        complemento = target - num_atual
        
        if complemento in conjunto:
            print(f"{conjunto[complemento] + 1} {i + 1}")
            return
        
        conjunto[num_atual] = i
        
    print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()