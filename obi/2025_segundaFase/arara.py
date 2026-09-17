n, m = map(int, input().split())
gaiolas = [0] * m
for i in range(0, m, 5):
    if n == 0: break
    gaiolas[i] = 1
    n -= 1
if n> 0:
    print("N")
else:
    print("S")