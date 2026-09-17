def main():
    N, K = map(int, input().split())
    S = input()

    freq = {}
    for i in range(N - K + 1):
        substring = S[i :i + K]
        freq[substring] = freq.get(substring, 0) +1
    
    max_freq = max(freq.values())

    res = []

    for sub in freq:
        if freq[sub] == max_freq:
            res.append(sub)

    res.sort()

    print(max_freq)
    print(" ".join(res))

main()