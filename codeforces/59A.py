palavra = input()
minusculas = 0
for i in palavra:
    if i == i.lower():
        minusculas += 1
if minusculas == len(palavra) / 2:
    print(palavra.lower())
elif minusculas > len(palavra) /2:
    print(palavra.lower())
else:
    print(palavra.upper())