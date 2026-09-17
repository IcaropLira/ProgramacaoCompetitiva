from math import gcd

def main():
    qnts = int(input())

    for i in range(qnts):
        n1, _, d1, op, n2, _, d2 = input().split()
        n1 = int(n1)
        n2 = int(n2)
        d1 = int(d1)
        d2 = int(d2)
        if op == "+":
            num = n1*d2 + n2*d1
            den = d1 * d2 
        elif op == "-":
            num = n1*d2 - n2*d1
            den = d1 * d2 
        elif op == "*":
            num = n1 * n2
            den = d1 * d2 
        else:
            num = n1 * d2
            den = d1 * n2 
        g = gcd(num, den)

        num_s = num // g
        den_s = den // g

        if den_s < 0:
            num_s *= -1
            den_s *= -1
        
        print(f"{num}/{den} = {num_s}/{den_s}")
main()