t = int(input())

for _ in range(t):
    x1,y1,x2,y2,x3,y3 = map(int, input().split())
    b1 = x2 - x1
    b2 = y2 - y1
    c1 = x3 - x1
    c2 = y3 - y1
    dif = b1 * c2 - b2 * c1

    if dif == 0:
        print("TOUCH")
    elif dif > 0:
        print("LEFT")
    else:
        print("RIGHT")


