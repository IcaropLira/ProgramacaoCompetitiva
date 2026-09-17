#Codeforces 510A
n, m = map(int, input().split())

hash = "#" * m
cob = "." * (m-1)
c = 0
for i in range(n -2):
    print(hash)
    c +=1
    if c == n: break
    print(cob + "#")
    c += 1
    if c == n: break
    print(hash)
    c += 1
    if c == n: break
    print("#" + cob)
    c += 1
    if c == n: break
