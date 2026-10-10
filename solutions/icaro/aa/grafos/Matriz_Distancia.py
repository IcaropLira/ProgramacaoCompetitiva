
class Grafo:

    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0] * self.vertices for i in range(self.vertices)]

    def adiciona_aresta(self, u, v, peso):
        self.grafo[u-1][v-1] = peso # trocar por += se for grafo multiplo

        #self.grafo[v-1][u-1] += 1 #caso o grafo nn seja direcionado

    def printm(self):
        for i in self.grafo:
            print(i)


#g = Grafo(4)
#g.adiciona_aresta(1,2)
#g.adiciona_aresta(3,4)
#g.adiciona_aresta(2,3)
#g.printm()

v = int(input("Quantidade de vértices: "))
g = Grafo(v)

a = int(input("Digite a quantidade de arestas: "))
for i in range(a):
    u, v, peso = map(int, input().split())
    g.adiciona_aresta(u, v, peso)

g.printm()
