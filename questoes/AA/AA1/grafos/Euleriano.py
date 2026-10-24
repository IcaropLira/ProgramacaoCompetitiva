class Grafo:

    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0] * self.vertices for i in range(self.vertices)]

    def adiciona_aresta(self, u, v):
        self.grafo[u-1][v-1] += 1 

        if u != v:
            self.grafo[v-1][u-1] += 1

    def printm(self):
        for i in self.grafo:
            print(i)

    def tem_aresta(self, u, v):
        if self.grafo[u-1][v-1] != 0:
            print(f"Existe {self.grafo[u-1][v-1]}  arestas entre os vértices {u} e {v}")
        else:
            print(f"Não tem aresta entre {u} e {v}")

    def eh_euleriano(self):
        contador = 0
        for i in range(self.vertices):
            grau = 0
            for j in range(self.vertices):
                if i == j: 
                    grau += 2 * self.grafo[i][j]
                else:
                    grau += self.grafo[i][j]

            if grau % 2 != 0:
                contador += 1
        if contador == 0:
            print(f"É um grafo Euleriano")
        elif contador == 2:
            print("É um grafo semieuleriano")
        else:
            print("O grafo não é Euleriano e nem semieuleriano")


g = Grafo(4)

g.adiciona_aresta(1,2)

g.adiciona_aresta(3,4)

g.adiciona_aresta(2,3)

g.adiciona_aresta(1,4)


g.printm()

g.eh_euleriano()

g.tem_aresta(2,4)

g.tem_aresta(1,2)