import math

class HeapMax:

    def __init__(self):
        self.nos = 0
        self.heap = []
    
    def adiciona_no(self, u):
        self.heap.append(u)
        self.nos += 1
        filho = self.nos

        while True:
            if filho == 1: break
            
            pai = filho // 2
            
            if self.heap[pai -1] >= self.heap[filho -1]: break #<= HEAPMIN

            else:
                self.heap[pai - 1], self.heap[filho -1] = self.heap[filho -1], self.heap[pai - 1]
                filho = pai


    def mostra_heap(self):
        print(self.heap)

    def mostra_estrutura(self):
        print("a Estrutura heap é a seguinte:")
        nivel = int(math.log(self.nos, 2))
        a = 0
        for i in range(nivel):
            for j in range(2 ** i):
                print(f"{self.heap[a]}", end="  ")
                a += 1
            print()
        for i in range(self.nos -a):
            print(f"{self.heap[a]}", end="  ")
            a += 1

h = HeapMax()

h.adiciona_no(17)
h.adiciona_no(36)
h.adiciona_no(25)
h.adiciona_no(7)
h.adiciona_no(3)
h.adiciona_no(100)
h.adiciona_no(1)
h.adiciona_no(2)
h.adiciona_no(19)

h.mostra_estrutura()








