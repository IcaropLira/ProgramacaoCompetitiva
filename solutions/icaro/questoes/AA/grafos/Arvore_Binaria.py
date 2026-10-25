class No:

    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

    def obterValor(self):
        return self.valor
    
    def setEsquerda(self, esquerda):
        self.esquerda = esquerda
    
    def setDireita(self, direita):
        self.direita = direita
    
    def obterEsquerda(self):
        return self.esquerda
    
    def obterDireita(self):
        return self.direita
    
no1 = No(4)
no2 = No(2)
no3 = No(5)

print(no1.obterValor())


no1.setEsquerda(no2)
no1.setDireita(no3)

print(no1.obterDireita().obterValor())