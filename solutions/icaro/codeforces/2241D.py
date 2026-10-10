n = int(input())
for i in range(n):
    m = int(input())
    nums1 = sorted(list(map(int, input().split())))
    nums2 = sorted(list(map(int, input().split())))
    if nums1 == nums2:
        print("YES")
    else:
        print("NO")