n = int(input())

quant = 0
menor = float('inf')
l = []
ym = 0
for i in range(n*2):
    x , y = map(int, input().split())
    s = x + y
    ym += y
    l.append(s)
    
l.sort(reverse=True)
for i in range(n):
    quant += abs(l[i])
    
print(quant-ym)
        