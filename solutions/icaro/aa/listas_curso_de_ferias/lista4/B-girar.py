def main():
    linhas = int(input())
    m = []
    
    for _ in range(linhas):
        m.append([str(x) for x in input().strip()])
    
    n = len(m)
    m_cols = len(m[0])

    top = 0
    bottom = n - 1
    left = 0
    right = m_cols - 1

    prev = m[top][left]

    for j in range(left + 1, right + 1):
        temp = m[top][j]
        m[top][j] = prev
        prev = temp

    for i in range(top + 1, bottom + 1):
        temp = m[i][right]
        m[i][right] = prev
        prev = temp

    for j in range(right - 1, left - 1, -1):
        temp = m[bottom][j]
        m[bottom][j] = prev
        prev = temp

    for i in range(bottom - 1, top - 1, -1):
        temp = m[i][left]
        m[i][left] = prev
        prev = temp

    for linha in m:
        print("".join(linha))

main()