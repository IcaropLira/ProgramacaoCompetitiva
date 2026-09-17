def conta_bubble(nums):
    c = 0
    for i in range(len(nums)):
        for j in range(len(nums) -1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                c += 1
    return c

def main():
    while True:
        entrada = input()
        if entrada == "0": break
        nums = [int(i) for i in entrada.split()]
        quantos = conta_bubble(nums)
        if quantos % 2 == 0:
            print("Carlos")
        else:
            print("Marcelo")
        

main()
