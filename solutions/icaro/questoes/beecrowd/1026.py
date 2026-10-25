
while True:
    try:
        a, b = map(int, input().split())

        n1 = f"{a:032b}"
        n2 = f"{b:032b}"
        n3 = list(f"{0:032b}")

        for i in range(len(n3)):
            if n1[i] == '1' and n2[i] == '1':
                n3[i] = '0'
            elif n1[i] == '1' or n2[i] == '1':
                n3[i] = '1'

        resultado = int("".join(n3), 2)
        print(resultado)

    except EOFError:
        break

    