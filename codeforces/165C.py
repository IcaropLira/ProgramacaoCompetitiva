K = int(input())
S = input()

frequencia_prefixo = {0: 1}
prefixo_atual = 0
resposta = 0

for caractere in S:
    if caractere == '1':
        prefixo_atual += 1
    
    prefixo_necessario = prefixo_atual - K
    
    if prefixo_necessario in frequencia_prefixo:
        resposta += frequencia_prefixo[prefixo_necessario]
    
    frequencia_prefixo[prefixo_atual] = frequencia_prefixo.get(prefixo_atual, 0) + 1

print(resposta)