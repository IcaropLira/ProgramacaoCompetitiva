def eh_primo(x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3, int(x**0.5) + 1, 2):
        if x % i == 0:
            return False
    return True

primos = []
num = 2
while len(primos) < 3501:
    if eh_primo(num):
        primos.append(num)
    num += 1

def josephus(n):
    res = 0
    for i in range(2, n + 1):
        res = (res + primos[n - i]) % i
    
    return res + 1

while True:
    try:
        line = input()
        if not line: break
        n = int(line)
        if n == 0:
            break
        print(josephus(n))
    except EOFError:
        break