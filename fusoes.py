import itertools
def union(a,b, pais):
    if pais[a] == pais[b]:
        return False   
    pais[a] = itertools.chain(pais[a] ,pais[b])
    pais[b] = pais[a]
    
    return True

    
n, m = [int(e) for e in input().split()]

dic = {}


for _ in range(m):
    linha = input().split()
    if linha[0] == "C":
        if linha[1] not in dic or linha[2] not in dic:
            print("N")
        elif dic[linha[1]] == dic[linha[2]]:
            print("S")
        else:
            print("N")
    elif linha[0] == "F":
        if linha[1] not in dic:
            dic[linha[1]] = [linha[2]]
        else:
            dic[linha[1]].append(linha[2])
        if linha[2] not in dic:
            dic[linha[2]] = [linha[1]]
        else:
            dic[linha[2]].append(linha[1])
        union(linha[1], linha[2], dic)