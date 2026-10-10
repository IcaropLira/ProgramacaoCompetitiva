def build_post(prefixo, infixo):
    if not prefixo:
        return ""

    raiz = prefixo[0]
    idx = infixo.index(raiz)

    inf_esq = infixo[:idx]
    inf_dir = infixo[idx+1:]

    pre_esq = prefixo[1:1+len(inf_esq)]
    pre_dir = prefixo[1+len(inf_esq):]

    esq = build_post(pre_esq, inf_esq)
    dir = build_post(pre_dir, inf_dir)

    return esq + dir + raiz


def main():
    C = int(input())
    for _ in range(C):
        N, pre, inf = input().split()
        print(build_post(pre, inf))

main()