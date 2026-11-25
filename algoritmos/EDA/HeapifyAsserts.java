public class HeapifyAsserts {

    public static void main(String[] args) {

        // Teste 1: heapify em uma folha não altera o array
        Heap h1 = new Heap(new int[]{10, 8, 9, 3, 5});
        h1.heapify(4);
        assert h1.toString().equals("[10, 8, 9, 3, 5]")
            : "Teste 1 falhou: heapify em folha não deve alterar o array. Obtido: " + h1.toString();

        // Teste 2: heapify na raiz quando filho direito é o maior
        // [1, 8, 9, 3, 5] → troca índice 0 (valor 1) com índice 2 (valor 9)
        // 1 desce para posição 2, que é folha → resultado: [9, 8, 1, 3, 5]
        Heap h2 = new Heap(new int[]{1, 8, 9, 3, 5});
        h2.heapify(0);
        assert h2.toString().equals("[9, 8, 1, 3, 5]")
            : "Teste 2 falhou: esperado [9, 8, 1, 3, 5]. Obtido: " + h2.toString();

        // Teste 3: heapify com efeito cascata (filho esquerdo é maior, desce dois níveis)
        // [1, 8, 7, 3, 5] → troca 0 com 1 → [8, 1, 7, 3, 5]
        //                 → troca 1 com 4 → [8, 5, 7, 3, 1]
        Heap h3 = new Heap(new int[]{1, 8, 7, 3, 5});
        h3.heapify(0);
        assert h3.toString().equals("[8, 5, 7, 3, 1]")
            : "Teste 3 falhou: esperado [8, 5, 7, 3, 1]. Obtido: " + h3.toString();

        // Teste 4: heapify na raiz de um max-heap já válido não altera nada
        Heap h4 = new Heap(new int[]{10, 8, 9, 3, 5});
        h4.heapify(0);
        assert h4.toString().equals("[10, 8, 9, 3, 5]")
            : "Teste 4 falhou: max-heap válido não deve ser alterado. Obtido: " + h4.toString();

        // Teste 5: heap com um único elemento
        Heap h5 = new Heap(new int[]{5});
        h5.heapify(0);
        assert h5.toString().equals("[5]")
            : "Teste 5 falhou: heap com único elemento. Obtido: " + h5.toString();

        // Teste 6: heapify em nó interno que não é a raiz
        // [10, 1, 9, 3, 5] → índice 1 (valor 1) tem filhos 3 (valor 3) e 4 (valor 5)
        // troca 1 com 4 → [10, 5, 9, 3, 1]
        Heap h6 = new Heap(new int[]{10, 1, 9, 3, 5});
        h6.heapify(1);
        assert h6.toString().equals("[10, 5, 9, 3, 1]")
            : "Teste 6 falhou: esperado [10, 5, 9, 3, 1]. Obtido: " + h6.toString();

        // Teste 7: heapify em árvore perfeita com cascata completa
        // [1, 10, 9, 8, 7, 6, 5] → 1 desce para folha
        // Primeiro swap: índice 0 (1) com índice 1 (10) → [10, 1, 9, 8, 7, 6, 5]
        // Segundo swap: índice 1 (1) com índice 3 (8) → [10, 8, 9, 1, 7, 6, 5]
        // Índice 3 é folha → fim
        Heap h7 = new Heap(new int[]{1, 10, 9, 8, 7, 6, 5});
        h7.heapify(0);
        assert h7.toString().equals("[10, 8, 9, 1, 7, 6, 5]")
            : "Teste 7 falhou: esperado [10, 8, 9, 1, 7, 6, 5]. Obtido: " + h7.toString();

        System.out.println("Todos os testes de HeapifyAsserts passaram!");
    }
}
