def main():
    entrada = input()
    letra = entrada[0]
    c = 0
    for i in entrada:
        if i == letra:
            c += 1
    if c == 1:
        print(letra)
    else:
        for i in entrada:
            if i != letra:
                print(i)
main()