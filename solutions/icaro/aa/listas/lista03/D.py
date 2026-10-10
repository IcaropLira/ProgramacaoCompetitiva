import sys
input = sys.stdin.readline

def total(s, maquinas, T):
    total = 0
    for i in maquinas:
        total += s // i
        if total >= T:
            return total
    return total


def main():
    N, T = map(int, input().split())
    maquinas = list(map(int, input().split()))

    minimo = 0
    maximo = min(maquinas) * T

    while minimo < maximo:
        meio = (minimo + maximo) // 2
        if total(meio, maquinas, T) >= T:
            maximo = meio
        else:
            minimo = meio + 1

    print(minimo)

main()