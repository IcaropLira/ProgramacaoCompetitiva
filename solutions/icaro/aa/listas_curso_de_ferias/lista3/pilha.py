def main():
    q = int(input())
    
    pilha = [0] * 100
    
    for _ in range(q):
        entrada = input().split()
        
        if entrada[0] == "1":
            x = int(entrada[1])
            pilha.append(x) 
        
        else:
            print(pilha.pop())

main()