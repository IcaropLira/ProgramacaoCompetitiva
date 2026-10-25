def main():
    n = int(input())
    login = False
    erros = 0
    for i in range(n):
        entrada = input()
        if entrada == "login":
            login = True
        elif entrada == "logout":
            login = False
        if not login and entrada == "private":
            erros += 1
    print(erros)
main()