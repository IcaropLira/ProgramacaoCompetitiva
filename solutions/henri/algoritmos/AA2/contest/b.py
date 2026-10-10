# incopleta
linha = input()

mySet = {}
for i in range(len(linha)):
    if linha[i] not in mySet:
        mySet[linha[i]] = 1
    else: 
        mySet[linha[i]] += 1

max = None
for i, e in mySet:
    if max == None or e > max:
        max = e

if len(linha) > 1 and max >= len(linha)/2: