from itertools import permutations

n = int(input())
p = tuple(map(int, input().split()))
q = tuple(map(int, input().split()))

perms = list(permutations(range(1, n + 1)))

print(abs(perms.index(p) - perms.index(q)))