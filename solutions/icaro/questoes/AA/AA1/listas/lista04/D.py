S = input()

zeros = S.count('0')
uns = S.count('1')

print(2 * min(zeros, uns))