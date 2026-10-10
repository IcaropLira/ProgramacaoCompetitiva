n = int(input())
c = 0 
notas = [100, 20, 10, 5, 1]
for i in notas:
    c += n // i
    n %= i
print(c)