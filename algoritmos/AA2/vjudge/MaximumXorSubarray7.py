end = "_end_"
def criarTrie(): return {}

def inserir(numero, trie):
    no_atual = trie
    for i in range(40, -1, -1):
        bit = (numero >> i) & 1
        if bit not in no_atual:
            no_atual[bit] = {}
        no_atual = no_atual[bit]

    no_atual[end] = True

def max_xor(numero, trie):
    no_atual = trie
    xor_max = 0
    for i in range(40, -1, -1):
        bit = (numero >> i) & 1
        bit_oposto = 1 - bit
        if bit_oposto in no_atual:
            xor_max |= 1 << i
            no_atual = no_atual[bit_oposto]
        else:
            no_atual = no_atual[bit]

    return xor_max

def solve():
    n = int(input())

    linha = list(map(int, input().split()))

    trie = criarTrie()
    

    for i in linha:
