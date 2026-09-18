def meu_pow(a, b):
    if b == 0:
        return 1
    if b % 2 == 0:
        metade = meu_pow(a, b/2)
        return metade * metade
    outro = meu_pow(a, b)
    return a * outro