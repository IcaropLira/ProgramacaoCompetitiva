def main():
    while True:
        qnts = int(input())
        if qnts == 0: break
        entrada = list(map(int, input().split()))
        count = 0

        for i in range(qnts):
            a = entrada[i]
            b = entrada[(i+1) % qnts]
            c = entrada[(i+2) % qnts]

            if (b > a and b > c) or (b < a and b < c):
                count += 1
        print(count)
            
main()