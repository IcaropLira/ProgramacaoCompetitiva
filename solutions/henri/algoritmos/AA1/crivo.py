def crivo(n):
    eh_primo = [True] * (n +1)
    eh_primo[0] = eh_primo[1] = False
    for i in range(2,int(n**0,5) +1):
        if eh_primo[i]:
            for j in range(i*i, n +1, i):
                eh_primo[j] = False
    return eh_primo

def crivo(n):
    eh_primo = [True] * (n+1)
    eh_primo[0] = eh_primo[0] = False
    for i in range(2, int(n**0,5) +1):
        if eh_primo[i]:
            for j in range(i*i, n +1, i):
                eh_primo[j] = False
    return eh_primo

def crivo(n):
    eh_primo = [True] * (n+1)
    eh_primo[0] = eh_primo[1] = False
    for i in range(2, int(n**0,5) +1):
        if eh_primo[i]:
            for j in range(i*i, n+1, i):
                eh_primo[j] = False
    return eh_primo

def crivo(n):
    eh_primo = [True] * (n+1)
    eh_primo[0] = eh_primo[1] = False
    for i in range(2, int(n**0,5) +1):
        if eh_primo[i]:
            for j in range(i*i, n + 1, i):
                eh_primo[j] = False
    return eh_primo

