N, Q = map(int, input().split())

seguindo = set()

for _ in range(Q):
    t, a, b = map(int, input().split())

    if t == 1:
        seguindo.add((a, b))

    elif t == 2:
        seguindo.discard((a, b))

    else:
        if (a, b) in seguindo and (b, a) in seguindo:
            print("Yes")
        else:
            print("No")