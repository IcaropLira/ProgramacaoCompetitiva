n = int(input())

dic = {5: 0, 10: 0, 20: 0}
lista = map(int, input().split())
resp = True
for e in lista:
    if e == 5:
        dic[5] +=1
    elif e == 10:
        if dic[5] == 0:
            resp = False
            break
        else:
            dic[5] -=1
            dic[10] += 1
    elif e == 20:
        if dic[10] == 0 and dic[5] >2:
            dic[5] -= 3
        elif dic[10] > 0 and dic[5] > 0:
            dic[5] -= 1
            dic[10] -= 1
        else:
            resp = False
            break
        
if resp:
    print()