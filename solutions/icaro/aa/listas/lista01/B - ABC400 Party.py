def main():
    fileiras = int(input())

    if 400 % fileiras != 0:
        print(-1)
    else:
        total = 400 / fileiras 
        print(int(total)) 

main()