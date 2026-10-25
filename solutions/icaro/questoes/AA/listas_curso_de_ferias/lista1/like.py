def main():
    n = int(input())
    
    resposta = 1000 
    for a in range(1, 10):
        for b in range(10):
            c = a * b
            if c < 10:  
                num = 100*a + 10*b + c
                if num >= n:
                    resposta = min(resposta, num)
    
    print(resposta)

main()