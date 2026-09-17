m = []
for i in range(5):
    m.append(list(map(int, input().split())))

for i in range(5):
    for j in range(5):
        if m[i][j] == 1:
            coord = (i, j)

a = abs(coord[0] - 2)
b = abs(coord[1] - 2)
c = a + b
print(c)