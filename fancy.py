n = int(input())

for _ in range(n):
    a  = int(input())
    
    num = 360/(180-a)
    
    if num == int(num) and num > 2:
        print("YES  ")
    else:
        print("NO")
    

# 3 = 180
# 4 = 360
# 5 = 540
# 6 = 720

# 90 * 3