entrada = input()
letras = set(entrada[1:len(entrada) -1].split(", "))
if "" in letras:
    letras.remove("")
print(len(letras))