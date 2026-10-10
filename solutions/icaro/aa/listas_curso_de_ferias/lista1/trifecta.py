def main():
    n = int(input())
    tempos = list(map(int, input().split()))
    
    cavalos = []
    for i in range(n):
        cavalos.append((tempos[i], i + 1)) 
    
    cavalos.sort()
    
    primeiro = cavalos[0][1]
    segundo = cavalos[1][1]
    terceiro = cavalos[2][1]
    
    print(primeiro, segundo, terceiro)

main()