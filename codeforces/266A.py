n = int(input())
palavra = input()
c = 0
for i in range(n-1):
    if (palavra[i] == palavra[i+1]):
        c += 1

print(c)