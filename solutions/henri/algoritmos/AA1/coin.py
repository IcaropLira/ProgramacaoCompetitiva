# forma imbecilica

def seila(quantidade, moedas):
    a = 0
    for i in range(len(moedas)-1, -1, -1):
        a = quantidade//moedas[i]
        while a*moedas[i] != quantidade:
            b = seila(quantidade-a, moedas[:i])
            a += b
            
        
    return a
    
    
    
moedas = list(map(int, input().split()))

quantidade = int(input())

print(seila(quantidade, moedas))
            
    
