def main():
    s, t = input().split()
    n = len(s)
    m = len(t)

    for w in range(1, n):
        for c in range(1, w + 1):
            linhas_validas = n // w
            if n % w >= c:
                linhas_validas += 1
            if linhas_validas != m:
                continue
            res = ""
            
            for i in range(0, n, w):
                pos = i + (c - 1)
                if pos < n:
                    res += s[pos]
            if res == t:
                print("Yes")
                return
    print("No")


main()