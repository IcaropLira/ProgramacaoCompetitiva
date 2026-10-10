def insertion_sort(array):
    i = array[1]
    ix = 1
    c = 0
    while True:
        for i in range(ix, 0, -1):
            if array[i] < array[i-1]:
                print(lista)
                c+= 1
                print(c)
                array[i],array[i-1] = array[i-1],array[i]
        ix += 1
        if ix == len(array) : break

lista = [9,8,7,6,5,4,3,2,1]
insertion_sort(lista)
print(lista)