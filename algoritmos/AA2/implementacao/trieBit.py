import sys
def criaTrie():
    return {}

def inserir(numero, trie):
    no_atual = trie
    for i in range(40, -1, -1):
        bit = (numero >> i) & 1
        if bit not in no_atual:
            no_atual[bit] = {}
        no_atual = no_atual[bit]

def max_xor(numero, trie):
    no_atual = trie
    xorMax = 0
    for i in range(40, -1, -1):
        bit = (numero >> i) & 1
        bit_oposto = 1 - bit
        if bit_oposto in no_atual:
            xorMax |= (1 << i)
            no_atual = no_atual[bit_oposto]
        else:
            no_atual = no_atual[bit]
    return xorMax

def solve():
    input = sys.stdin.readline
    n = int(input())

    for _ in range(n):
        t = int(input())
        linha = list(map(int, input().split()))

        trie = criaTrie()
        inserir(linha[0], trie)
        r = 0
        for x in linha[1:]:
            r = max(r, max_xor(x, trie))
            inserir(x, trie)
        print(r)
# sei
if __name__ == "__main__":
    solve()