def main():
    n = input()

    m = 0
    for c in n:
        if c == "4" or c == "7":
            m += 1

    for c in str(m):
        if c != "4" and c != "7":
            print("NO")
            return

    print("YES")

main()