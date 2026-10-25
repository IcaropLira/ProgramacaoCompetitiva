def backtrack(start_index, caminho_atual, nums, res):
    #1 Caso Base: Toda chamada é um subconjunto válido
    res.append(caminho_atual[:])
    #2 Tentar todas as escolhas possíveis a partir de start_idx
    for i in range(start_index, len(nums)):
        #3 Verificar se essa escolha é válida: toda escolha é válida
        #4 fazer a escolha: adiciona nums[i] ao subconjunto atual
        caminho_atual.append(nums[i])#empilha escolha
        