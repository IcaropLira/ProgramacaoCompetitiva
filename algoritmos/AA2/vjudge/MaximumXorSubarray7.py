import sys
end = "_end_"
def criarTrie(): return {}

def inserir(numero, trie):
    no_atual = trie
    for i in range(30, -1, -1):
        bit = (numero >> i) & 1
        if bit not in no_atual:
            no_atual[bit] = {}
        no_atual = no_atual[bit]

    no_atual[end] = True

def max_xor(numero, trie):
    no_atual = trie
    xor_max = 0
    for i in range(30, -1, -1):
        bit = (numero >> i) & 1
        bit_oposto = 1 - bit
        if bit_oposto in no_atual:
            xor_max |= 1 << i
            no_atual = no_atual[bit_oposto]
        else:
            no_atual = no_atual[bit]

    return xor_max

def solve():
    input = sys.stdin.readline
    n = int(input())

    linha = list(map(int, input().split()))

    trie = criarTrie()
    
    saida = 0
    pre = 0

    inserir(0, trie)

    for i in linha:
        pre ^= i
        saida = max(saida, max_xor(pre, trie))
        inserir(pre, trie)

    print(saida)

if __name__ == "__main__":
    solve()
