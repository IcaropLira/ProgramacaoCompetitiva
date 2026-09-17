n, h = map(int, input().split())
alturas = list(map(int, input().split()))

largura = 0

for altura in alturas:
    if altura > h:
        largura += 2
    else:
        largura += 1

print(largura)