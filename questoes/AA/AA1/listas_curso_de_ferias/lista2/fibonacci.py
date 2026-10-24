def f(x):
    return int(str(x)[::-1])

def main():
    X, Y = map(int, input().split())
    
    a1 = X
    a2 = Y
    
    for _ in range(3, 11):
        a3 = f(a1 + a2)
        a1, a2 = a2, a3
    
    print(a2)

main()