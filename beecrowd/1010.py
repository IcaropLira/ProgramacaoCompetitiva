n1 = [float(i) for i in input().split()]
n2 = [float(i) for i in input().split()]
n3 = n1[1] * n1[2] + n2[1] * n2[2]
print(f"VALOR A PAGAR: R$ {n3:.2f}")