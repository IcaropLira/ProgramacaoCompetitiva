import sys
input = sys.stdin.readline

def main():
    N, T = map(int, input().split())
    maquinas = list(map(int, input().split()))

    maquinas.sort()
    maqs = maquinas

    minimo = 0
    maximo = maqs[0] * T

    while minimo < maximo:
        meio = (minimo + maximo) // 2

        total = 0
        for i in maqs:
            if i > meio:
                break
            total += meio // i
            if total >= T:
                break

        if total >= T:
            maximo = meio
        else:
            minimo = meio + 1

    print(minimo)

main()