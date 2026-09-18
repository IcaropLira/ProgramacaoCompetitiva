frase = input()
lista = set()
letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

for e in frase:
    if e in letras:
        lista.add(e)
        
print(len(lista))