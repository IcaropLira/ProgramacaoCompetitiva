def main():
    entrada = input()
    pilha = []
    for i in entrada:
        if i == "0":
            pilha.append("0")
        elif i == "1":
            pilha.append("1")
        else:
            if pilha: pilha.pop()
    print("".join(pilha))



main()