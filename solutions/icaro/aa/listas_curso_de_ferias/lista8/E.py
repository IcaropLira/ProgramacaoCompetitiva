import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())

    grafo = [[] for _ in range(N)]

    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        grafo[a].append(b)
        grafo[b].append(a)

    # checar grau
    for i in range(N):
        if len(grafo[i]) > 2:
            print("No")
            return

    visitado = [False] * N

    def has_cycle(start):
        stack = [(start, -1)]
        
        while stack:
            u, pai = stack.pop()
            
            if visitado[u]:
                continue
            
            visitado[u] = True
            
            for v in grafo[u]:
                if not visitado[v]:
                    stack.append((v, u))
                elif v != pai:
                    return True
        
        return False

    for i in range(N):
        if not visitado[i]:
            if has_cycle(i):
                print("No")
                return

    print("Yes")


if __name__ == "__main__":
    main()