def main():    
    s = input().strip()

    i = 0
    ops = 0

    while i < len(s):
        if i + 1 < len(s) and s[i] == '0' and s[i+1] == '0':
            ops += 1
            i += 2
        else:
            ops += 1
            i += 1

    print(ops)

main()