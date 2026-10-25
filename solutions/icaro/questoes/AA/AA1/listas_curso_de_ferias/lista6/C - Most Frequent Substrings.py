n, k = map(int, input().split())
s = input()

freq = {}

for i in range(n - k + 1):
    sub = s[i:i+k]
    freq[sub] = freq.get(sub, 0) + 1

mx = max(freq.values())

resp = [sub for sub in freq if freq[sub] == mx]

resp.sort()

print(mx)
print(*resp)