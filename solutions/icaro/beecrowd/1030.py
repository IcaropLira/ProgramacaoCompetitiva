def josephus(n, k):
    res = 0
    for i in range(2, n + 1):
        res = (res + k) % i
    return res + 1 

def main():
    qnts = int(input())
    for i in range(qnts):
        N, K = map(int, input().split())
        print(f"Case {i +1 }: {josephus(N, K)}")


main()