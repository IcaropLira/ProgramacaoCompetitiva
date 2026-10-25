import sys
input = sys.stdin.readline

def main():
    N, T = map(int, input().split())
    maquinas = list(map(int, input().split()))

    minimo = 0
    maximo = min(maquinas) * T

    maqs = maquinas

    while minimo < maximo:
        meio = (minimo + maximo) // 2

        total = 0
        for i in maqs:
            total += meio // i
            if total >= T:
                break

        if total >= T:
            maximo = meio
        else:
            minimo = meio + 1

    print(minimo)

main()