def custo(c, mediana,  nums):
    custo = 0
    for i in range(mediana, len(nums)):
        custo += max(0, c - nums[i])
    return custo

def main():

    N, K = map(int, input().split())

    nums = list(map(int, input().split()))
    nums.sort()

    mediana = (len(nums) //2)

    maximo = nums[mediana] + K
    minimo = 0
    meio = (maximo // 2) 

    while maximo > minimo:
        c = custo(meio, mediana, nums)
        if c <= K:
            minimo = meio
        else:
            maximo = meio - 1
        meio = (minimo + maximo + 1) // 2
    print(minimo)
main()