n, m = map(int, input().split())
s = list(input())
j = 0
while m > 0:
    while j < n-1:
        if s[j] == "B" and s[j+1] == "G":
            s[j], s[j+1] = s[j+1], s[j]
            j+= 1
        j+= 1
    j = 0
    m -=1
print("".join(s)) 