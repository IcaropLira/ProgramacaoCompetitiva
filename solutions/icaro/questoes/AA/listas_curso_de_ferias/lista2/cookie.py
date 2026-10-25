def main():
    entrada = input().split()
    N = int(entrada[0])
    D = int(entrada[1])

    S = list(input())

    for i in range(N - 1, -1, -1):
        if S[i] == '@' and D > 0:
            S[i] = '.'
            D -= 1

    print("".join(S))

main()