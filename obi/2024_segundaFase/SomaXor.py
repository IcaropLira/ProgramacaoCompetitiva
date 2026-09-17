n = int(input())
nums = list(map(int, input().split()))

prefix = [0]

for x in nums:
    prefix.append(prefix[-1] ^ x)

ans = 0

for bit in range(30):

    zero = 0
    one = 0

    for p in prefix:
        if (p >> bit) & 1:
            one += 1
        else:
            zero += 1

    ans += zero * one * (1 << bit)

print(ans)