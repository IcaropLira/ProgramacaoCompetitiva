import sys
end = "_end_"

def criaTrie():
    return {}

def insere(numero, trie):
    no_atual = trie
    for digito in numero:
        if digito not in no_atual:
            no_atual[digito] = {}
        no_atual = no_atual[digito]
    no_atual[end] = True

def buscar_prefixo(numero, trie):
    no_atual = trie
    for digito in numero:
        if end in no_atual:
            return True
        if digito not in no_atual:
            return False
        no_atual = no_atual[digito]
    return True

def solve():
    input = sys.stdin.readline
    n = int(input())
    for _ in range(n):
        trie = criaTrie()
        t = int(input())
        linha = input()[0:-1]

        insere(linha, trie)
        ta = False
        for i in range(1, t):
            linha = input()[0:-1]
            if buscar_prefixo(linha, trie):
                ta = True
                
            insere(linha, trie)

        if not ta:
            print("YES")
        else: print("NO")


if __name__ == "__main__":
    solve()