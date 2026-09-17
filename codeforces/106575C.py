t = int(input())

for i in range(t):
    a, b, c = map(int, input().split())
    print(f"{(c*a*a)/(b*b):.10f}")