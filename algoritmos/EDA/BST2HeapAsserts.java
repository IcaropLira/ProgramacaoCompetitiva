import java.util.Arrays;

public class BST2HeapAsserts {

    /**
     * Verifica se o array satisfaz a propriedade de max-heap usando índices de
     * árvore binária completa (pai no índice i, filhos em 2i+1 e 2i+2).
     */
    private static boolean isMaxHeap(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int left  = 2 * i + 1;
            int right = 2 * i + 2;
            if (left  < arr.length && arr[i] < arr[left])  return false;
            if (right < arr.length && arr[i] < arr[right]) return false;
        }
        return true;
    }

    public static void main(String[] args) {

        // Teste 1: BST com único elemento
        BST bst1 = new BST();
        bst1.add(5);
        bst1.toMaxHeap();
        int[] heap1 = bst1.toLevelOrderArray();
        assert heap1.length == 1
            : "Teste 1 falhou: tamanho esperado 1, obtido " + heap1.length;
        assert heap1[0] == 5
            : "Teste 1 falhou: esperado [5], obtido " + Arrays.toString(heap1);

        // Teste 2: BST com 3 elementos formando árvore completa
        // Inserção [5, 3, 7]:
        //     5
        //    / \
        //   3   7
        // In-order: [3, 5, 7]  →  nível-a-nível mais-for-primeiro: [7, 5, 3]
        BST bst2 = new BST();
        bst2.add(new int[]{5, 3, 7});
        bst2.toMaxHeap();
        int[] heap2 = bst2.toLevelOrderArray();
        assert heap2.length == 3
            : "Teste 2 falhou: tamanho esperado 3, obtido " + heap2.length;
        assert isMaxHeap(heap2)
            : "Teste 2 falhou: resultado não é um max-heap: " + Arrays.toString(heap2);
        assert heap2[0] == 7
            : "Teste 2 falhou: raiz deve ser 7 (máximo), obtido " + heap2[0];

        // Teste 3: BST com 7 elementos formando árvore perfeita
        // Inserção [4, 2, 6, 1, 3, 5, 7]:
        //         4
        //        / \
        //       2   6
        //      / \ / \
        //     1  3 5  7
        // In-order: [1, 2, 3, 4, 5, 6, 7]  →  BFS mais-for-primeiro: [7, 6, 5, 4, 3, 2, 1]
        BST bst3 = new BST();
        bst3.add(new int[]{4, 2, 6, 1, 3, 5, 7});
        bst3.toMaxHeap();
        int[] heap3 = bst3.toLevelOrderArray();
        assert heap3.length == 7
            : "Teste 3 falhou: tamanho esperado 7, obtido " + heap3.length;
        assert isMaxHeap(heap3)
            : "Teste 3 falhou: resultado não é um max-heap: " + Arrays.toString(heap3);
        assert heap3[0] == 7
            : "Teste 3 falhou: raiz deve ser 7 (máximo), obtido " + heap3[0];
        assert Arrays.equals(heap3, new int[]{7, 6, 5, 4, 3, 2, 1})
            : "Teste 3 falhou: esperado [7, 6, 5, 4, 3, 2, 1], obtido " + Arrays.toString(heap3);

        // Teste 4: verifica que a raiz é sempre o maior elemento (invariante fundamental)
        BST bst4 = new BST();
        bst4.add(new int[]{10, 5, 15, 3, 7, 12, 20});
        bst4.toMaxHeap();
        int[] heap4 = bst4.toLevelOrderArray();
        assert heap4.length == 7
            : "Teste 4 falhou: tamanho esperado 7, obtido " + heap4.length;
        assert isMaxHeap(heap4)
            : "Teste 4 falhou: resultado não é um max-heap: " + Arrays.toString(heap4);
        assert heap4[0] == 20
            : "Teste 4 falhou: raiz deve ser 20 (máximo), obtido " + heap4[0];

        // Teste 5: BST com 2 elementos (raiz e filho direito)
        // Inserção [3, 7]:
        //   3
        //    \
        //     7
        // In-order: [3, 7]  →  nível-a-nível mais-for-primeiro: raiz=7, filho.right=3
        BST bst5 = new BST();
        bst5.add(new int[]{3, 7});
        bst5.toMaxHeap();
        int[] heap5 = bst5.toLevelOrderArray();
        assert heap5.length == 2
            : "Teste 5 falhou: tamanho esperado 2, obtido " + heap5.length;
        assert heap5[0] == 7
            : "Teste 5 falhou: raiz deve ser 7 (máximo), obtido " + heap5[0];

        System.out.println("Todos os testes de BST2HeapAsserts passaram!");
    }
}
