def main():
    palavra = input()
    if palavra[0] == palavra[len(palavra) -1]:
        print("Yes")
    else:
        print("No")
main()