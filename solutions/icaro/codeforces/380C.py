s = input()
pilha = []
prefix = []

total = 0
for i in s:
    pilha.append(i)
    if len(pilha) >=2 :
        while len(pilha) >= 2 and pilha[-1] == ")" and pilha[-2] == "(":
            total +=2
            pilha.pop()
            pilha.pop()
        
    prefix.append(total)
q = int(input())
print(prefix)
for _ in range(q):
    a, b = map(int, input().split())
    a -=1
    b -=1
    print(prefix[b] - prefix[a])