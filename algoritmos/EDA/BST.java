import java.util.*;

public class BST {

    private Node root;
    private int size;
    
    public boolean isEmpty() {
        return this.root == null;
    }

    public void add(int[] v) {
        for (int i = 0; i < v.length; i++)
            this.add(v[i]);
    }

    
    /**
     * Implementação iterativa da adição de um elemento em uma árvore binária de pequisa.
     * @param element o valor a ser adicionado na árvore.
     */
    public void add(int element) {
        this.size += 1;
        if (isEmpty())
            this.root = new Node(element);
        else {
            
            Node aux = this.root;
            
            while (aux != null) {
                
                if (element < aux.value) {
                    if (aux.left == null) { 
                        Node newNode = new Node(element);
                        aux.left = newNode;
                        newNode.parent = aux;
                        return;
                    }
                    
                    aux = aux.left;
                } else {
                    if (aux.right == null) { 
                        Node newNode = new Node(element);
                        aux.right = newNode;
                        newNode.parent = aux;
                        return;
                    }
                    
                    aux = aux.right;
                }
            }
        }
        
    }
    
    
    /**
     * Retorna o nó que contém o valor máximo da árvore. Implementação recursiva.
     * @return o nó contendo o valor máximo da árvore ou null se a árvore estiver vazia.
     */
    public Node min() {
        if (isEmpty()) return null;
        return min(this.root);
    }
    
    /**
     * Retorna o nó que contém o valor máximo da árvore cuja raiz é passada como parâmetro. Implementação recursiva.
     * @param a raiz da árvore.
     * @return o nó contendo o valor máximo da árvore ou null se a árvore estiver vazia.
     */
    private Node min(Node node) {
        if (node.left == null) return node;
        else return min(node.left);
    }

    /**
     * Retorna o nó que contém o valor máximo da árvore. Implementação iterativa.
     * @return o nó contendo o valor máximo da árvore ou null se a árvore estiver vazia.
     */
    public Node max() {
        if (isEmpty()) return null;
        
        Node node = this.root;
        while(node.right != null)
            node = node.right;
        
        return node;
    }
    
    /**
     * Retorna o nó que contém o valor máximo da árvore cuja raiz é passada como parâmetro. Implementação recursiva.
     * @param raiz da árvore.
     * @return o nó contendo o valor máximo da árvore ou null se a árvore estiver vazia.
     */
    
    private Node max(Node node) {
        if (node.right == null) return node;
        else return max(node.right);
    }
    
    /**
     * Transforma esta BST em um max-heap sem alterar a estrutura da árvore. Ou seja,
     * não pode inserir, nem remover nós, apenas alterar os valores.
     * Dica: use percursos em árvore para obter os valores ordenados e para
     * percorrer os nós na ordem que um heap espera.
     */
    public void toMaxHeap() {
        if (root == null) return;
        int[] list = new int[this.size];
        Node atual = min();
        int idx = 0;
        while (atual!=null){
            list[idx++] = (atual.value);
            atual = sucessor(atual);
        }


        Queue<Node> queue = new ArrayDeque<>(this.size / 2 + 1);
        queue.add(root);

        int i = this.size -1;

        while (!queue.isEmpty()){
            Node current = queue.poll();
            current.value = list[i--];

            if (current.left != null){
                queue.add(current.left);
            }
            if(current.right != null){
                queue.add(current.right);
            }
        }

    }

    public Node sucessor(Node node) {
        if (node == null) return null;
        
        if (node.right != null)
            return min(node.right);
        else {
            Node aux = node.parent;
            
            while (aux != null && aux.value < node.value)
                aux = aux.parent;
            
            return aux;
        }
    }
    

   

    public int[] toLevelOrderArray() {
        if (isEmpty()) return new int[0];
        List<Integer> values = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(this.root);
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            values.add(node.value);
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        int[] result = new int[values.size()];
        for (int i = 0; i < values.size(); i++)
            result[i] = values.get(i);
        return result;
    }

}

    
class Node {
    
    int value;
    Node left;
    Node right;
    Node parent;
    
    Node(int v) {
        this.value = v;
    }

    public String toString() {
        return this.value+"";
    }

    public boolean hasOnlyLeftChild() {
        return (this.left != null && this.right == null);
    }
    
    public boolean hasOnlyRightChild() {
        return (this.left == null && this.right != null);
    }

    public boolean isLeaf() {
        return this.left == null && this.right == null;
    }
    
}
