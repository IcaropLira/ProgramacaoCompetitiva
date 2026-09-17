from bisect import bisect_right

n = int(input())
precos = list(map(int, input().split()))

precos.sort()

q = int(input())

for _ in range(q):
    dinheiro = int(input())
    print(bisect_right(precos, dinheiro))