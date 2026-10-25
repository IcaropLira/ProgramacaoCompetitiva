a = (input())
b = (input())
res = []
for i in range(len(a)):
    res.append(str(int(a[i]) ^int(b[i])))
print("".join(res))