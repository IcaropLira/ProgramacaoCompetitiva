def main():
    s, n = map(int, input().split())

    dragoes = []

    for i in range(n):
        x, y = map(int, input().split())
        dragoes.append((x, y))

    dragoes.sort()
    for i in dragoes:
        if s> i[0]:
            s+= i[1]
        else: 
            print("NO")
            return
    print("YES")
main()