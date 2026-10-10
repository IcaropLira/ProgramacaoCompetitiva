pi = 3.14159
n = [float(i) for i in input().split()]
a = n[0] * n[2] /2
b = n[2] ** 2 * pi
c = ((n[0] + n[1]) * n[2]) / 2
d = n[1] ** 2
e = n[0] * n[1]
print(f"""TRIANGULO: {a:.3f}
CIRCULO: {b:.3f}
TRAPEZIO: {c:.3f}
QUADRADO: {d:.3f}
RETANGULO: {e:.3f}""")