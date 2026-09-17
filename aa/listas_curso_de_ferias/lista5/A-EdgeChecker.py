def main():
    nums = {
        1 : {10, 2},
        2 : {1, 3},
        3 : {2, 4},
        4 : {3, 5},
        5 : {4, 6},
        6 : {5, 7},
        7 : {6, 8},
        8 : {7, 9},
        9 : {8, 10},
        10 : {9, 1},
    }

    n1, n2 = (int(i) for i in input().split())
    if n2 in nums[n1]:
        print("Yes")
    else:
        print("No")

main()