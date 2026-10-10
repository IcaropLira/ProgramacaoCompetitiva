def solve():
    while True:
        try:
            n = int(input())
            if n == 0:
                break
            
            # Testamos valores de m começando por 1
            m = 1
            while True:
                # O problema diz que a região 1 é desligada primeiro.
                # Restam n-1 regiões. Queremos que a região 13 seja a última.
                # Como a 1 sumiu, as 12 regiões antes da 13 tornam-se 11.
                # Portanto, o alvo no Josephus de (n-1) elementos é o índice 11.
                
                if remaining_survivor(n - 1, m) == 11:
                    print(m)
                    break
                m += 1
        except EOFError:
            break

def remaining_survivor(n, m):
    """
    Calcula a posição do último sobrevivente para n elementos e salto m.
    Usando a fórmula iterativa de Josephus (indexada em 0).
    """
    pos = 0
    for i in range(1, n + 1):
        pos = (pos + m) % i
    return pos

if __name__ == "__main__":
    solve()