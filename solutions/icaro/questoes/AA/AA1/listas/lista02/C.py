
n1 = int(input())
a = bin(n1)
c = 0
for i in a[2:]:
    if i == "1":
        c += 1 
print(c)
