n = int(input())
for i in range(n):
    m = int(input())
    linhas = input().split("*")
    if linhas:
        maior = len(max(linhas))
        if maior % 2 == 0:
            maior //= 2
        else:
            maior = maior // 2 +1
    else:
        maior = 0
    print(maior) 



    