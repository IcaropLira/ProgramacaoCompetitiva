# incopleta
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

linha1 = list(map(int, input().split()))
linha2 = list(map(int, input().split()))

linhaSort = [[linha1[i], i] for i in range(len(linha1))]
linhaSort.sort()


for i in range(m):
    eh = False
    menor = None
    for j in range(n):
        if linha2[i] >= linha1[j]:
            menor = j
            break
        if linha2[i] >= linhaSort[j][0]:
            if menor == None or menor > linhaSort[j][1]:
                menor = linhaSort[j][1]
        else:
            break
            
    if menor == None:
        print(-1)
    else:
        print(menor+1)