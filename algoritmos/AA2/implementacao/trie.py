end = "_end_"


def ciarTrie():
    return {}

def inserir(palavra, trie):
    no_atual = trie
    for letra in palavra:
        if letra not in no_atual:
            no_atual[letra] = {}
        no_atual = no_atual[letra]
    no_atual[end] = True

def buscar_palavra(palavra, trie):
    no_atual = trie
    for letra in palavra:
        if letra not in no_atual:
            return False
        no_atual = no_atual[letra]
    return end in no_atual

def buscar_prefixo(palavra, trie):
    no_atual = trie
    for letra in palavra:
        if letra not in no_atual:
            return False
        no_atual = no_atual[letra]
    return True