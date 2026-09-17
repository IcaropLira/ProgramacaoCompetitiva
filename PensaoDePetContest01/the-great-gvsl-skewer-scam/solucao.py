def main():
    n = int(input())
    a = list(map(int, input().split()))

    total = sum(a)

    possible_sums = {0}

    for v in a:
        new_sums = set()

        for s in possible_sums:
            new_sums.add(s + v)

        possible_sums.update(new_sums)

    ans = float('inf')

    for s in possible_sums:
        ans = min(ans, abs(total - 2 * s))

    print(ans)


if __name__ == "__main__":
    main()