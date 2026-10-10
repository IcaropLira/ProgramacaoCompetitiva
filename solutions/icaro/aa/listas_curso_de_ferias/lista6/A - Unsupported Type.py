def main():
    n1 = int(input().strip())
    nums = {int(i) for i in input().split()}
    x = int(input())
    if x in nums:
        print("Yes")
    else:
        print("No")


main()