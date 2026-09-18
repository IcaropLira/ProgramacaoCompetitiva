n, q = input().split()
n, q = int(n), int(q)
dici = {}

for _ in range(q):
    t, a, b = input().split()
    if t == '1':
        if a not in dici:
            dici[a] = {b}
        elif a in dici:
            dici[a].add(b)
    elif t == '2':
        if a in dici:
            dici[a].discard(b)
    elif t == '3':
        if a not in dici or b not in dici:
            print("No")
        else :
            if a in dici[b] and b in dici[a]:
                print("Yes")
            else:
                print("No")