def main():
    c = 1
    first = True
    
    while True:
        qnt = int(input())
        if qnt == 0:
            break
        
        if not first:
            print()
        first = False
        
        consumo_total = 0
        total_pessoas = 0
        
        casas = {}
        
        for _ in range(qnt):
            moradores, consumo = map(int, input().split())
            
            consumo_total += consumo
            total_pessoas += moradores
            
            consumo_unitario = consumo // moradores
            
            if consumo_unitario not in casas:
                casas[consumo_unitario] = 0
            casas[consumo_unitario] += moradores
        
        print(f"Cidade# {c}:")
        
        ordenado = sorted(casas.items())
        
        for i in range(len(ordenado)):
            consumo_unitario, moradores = ordenado[i]
            
            if i > 0:
                print(" ", end="")
            print(f"{moradores}-{consumo_unitario}", end="")
        
        print()
        
        consumo_medio = (consumo_total * 100) // total_pessoas
        consumo_medio /= 100
        
        print(f"Consumo medio: {consumo_medio:.2f} m3.")
        
        c += 1


main()