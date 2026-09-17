entrada = input().split()
N = int(entrada[0])
M = int(entrada[1])


entrada = input().split()
A = []
for x in entrada:
    A.append(int(x))


entrada = input().split()
B = []
for x in entrada:
    B.append(int(x))

posA = [0] * N
posB = [0] * M

i = 0
j = 0
k = 1 

while i < N and j < M:
    
    if A[i] < B[j]:
        posA[i] = k
        i += 1
    else:
        posB[j] = k
        j += 1
    
    k += 1

while i < N:
    posA[i] = k
    i += 1
    k += 1

while j < M:
    posB[j] = k
    j += 1
    k += 1
print(*posA)
print(*posB)