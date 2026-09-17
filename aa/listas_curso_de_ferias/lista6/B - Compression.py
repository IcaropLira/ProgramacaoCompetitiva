def main():
    n1 = int(input())
    nums = sorted(set([int(i) for i in input().split()]))
    print(len(nums))
    print(" ".join(str(i) for i in nums))

main()