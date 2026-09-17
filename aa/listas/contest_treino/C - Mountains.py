entrada = input()
c = 0
alturas = []
for i in entrada:
    if i == "+":
        c+= 1
    else:
        c -= 1
    alturas.append(c)
print(alturas.index(max(alturas)) + 1)