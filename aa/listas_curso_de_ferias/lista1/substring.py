def main():
    n, a, b = [int(i) for i in input().split()]

    s = input()
    word = ""
    for i in range(a, len(s) - (b)):
        word += s[i]
    print(word)
main()