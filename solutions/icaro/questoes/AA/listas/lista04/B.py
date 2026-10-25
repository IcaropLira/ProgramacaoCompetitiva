S = input()
palavra = []
for i in S:
    if i == "B" and palavra:
        palavra.pop()
    elif i != "B":
        palavra.append(i)
print("".join(palavra))