import bisect

qnts = int(input())

vermes = list(map(int, input().split()))
pilhas = []
a = 1
"""
for i in range(len(vermes)):
    pilhas.append(list(range(a, a+ vermes[i])))
    a += vermes[i]

"""
for i in range(len(vermes)):
    pilhas.append((a, a+ vermes[i] -1))
    a += vermes[i]

Q = int(input())

consultas = list(map(int, input().split()))
"""
for i in range(Q):
    for j in range(len(pilhas)):
        if consultas[i] <= pilhas[j][1]:
            print(j + 1)
            break
"""
valores = [p[1] for p in pilhas]

for i in range(Q):
    pos = bisect.bisect_left(valores, consultas[i])
    if pos < len(valores):
        print(pos+1)