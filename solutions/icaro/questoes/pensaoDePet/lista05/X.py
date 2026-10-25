def eh_primo(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
 
def main():
    n, m = map(int, input().split())
    
    if not eh_primo(m):
        print("NO")
        return
 
    for i in range(n+1, m +1):
        if eh_primo(i):
            primeiro = i
            if primeiro == m:
                print("YES")
                return None
            else:
                print("NO")
                return None
main()