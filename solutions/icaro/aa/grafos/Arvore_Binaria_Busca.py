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
    
class ArvoreBinariaBusca:

    def __init__(self):
        self.raiz = None

    def obterRaiz(self):
        return self.raiz
    
    def insere(self, valor):
        no = No(valor)
        if self.raiz == None:
            self.raiz = no
        else:
            no_atual = self.raiz
            no_pai = None
            
            while True:
                if no_atual != None:
                    no_pai = no_atual
                    if no.obterValor() < no_atual.obterValor():
                        no_atual = no_atual.obterEsquerda()
                    else:
                        no_atual = no_atual.obterDireita()
                else:
                    if no.obterValor() < no_pai.obterValor():
                        no_pai.setEsquerda(no)
                    else:
                        no_pai.setDireita(no)
                    break

    def mostraArvore(self, no_atual): #percurso em ordem simétrica
        if no_atual != None:
            self.mostraArvore(no_atual.obterEsquerda())
            print(f"{no_atual.obterValor()}", end="  ") #passar esse pra cima vira preordem, pos ordem passar por último
            self.mostraArvore(no_atual.obterDireita())

t = ArvoreBinariaBusca()
t.insere(8)
t.insere(3)
t.insere(6)
t.insere(10)
t.insere(14)
t.insere(1)
t.insere(7)
t.insere(13)
t.insere(4)

t.mostraArvore(t.obterRaiz())
