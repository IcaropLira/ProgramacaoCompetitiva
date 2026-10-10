import random
import sys

def main():
    n = int(sys.argv[1])
    max_a = int(sys.argv[2])

    print(n)

    a = []
    for _ in range(n):
        a.append(random.randint(1, max_a))

    print(*a)

if __name__ == "__main__":
    main()