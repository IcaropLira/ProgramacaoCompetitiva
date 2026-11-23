package eda;
import java.util.*;

public class BST {
    private Node root;
    private int size;

    public BST(){
        this.size = 0;
        this.root = null;
    }

    public boolean isEmpty(){
        return this.root == null;
    }

    public void add(int element){
        this.size += 1;
        if (isEmpty()){
            this.root = new Node(element);
        } else {
            Node aux = this.root;
            while (aux != null) {
                
                if (element < aux.value){
                    if (aux.left == null){
                        Node newNode = new Node(element);
                        aux.left = newNode;
                        newNode.parent = aux;
                        return;
                    }

                    aux = aux.left;
    
                } else{
                    if (aux.right == null){
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

    public Node min(){
        if(isEmpty()){
            return null;
        }
        return min(this.root);
    }

    public Node min(Node node){
        if(node.left == null){
            return node;
        }
        return min(node.left);
    }
    public Node max(){
        if(isEmpty()){
            return null;
        }
        return max(this.root);
    }

    public Node max(Node node){
        if(node.right == null){
            return node;
        }
        return max(node.right);
    }

    public Node predecessor(Node node){
        if (node == null){
            return null;
        }
        if(node.left != null){
            return max(node.left);
        }
        else {
            Node aux = node.parent;
            while (aux != null && aux.value > node.value) {
                aux = aux.parent;
            }

            return aux;
        }
    }

    public Node sucessor(Node node){
        if (node == null){
            return null;
        }
        if(node.right != null){
            return min(node.right);
        }
        else {
            Node aux = node.parent;
            while (aux.parent != null && aux.value < node.value) {
                aux = aux.parent;
            }

            return aux;
        }
    }

    public Node search(int value){
       
        Node aux = this.root;

        while(aux != null){
            if (aux.value == value){
                return aux;
            } else if (value > aux.value){
                aux = aux.right;
            } else {
                aux = aux.left;
            }
        }

        return aux;
    
    }

    public void remove(Node node){
        if (node.isLeaf()){
            if (node == this.root){
                this.root = null;
            } else {
                if (node.value > node.parent.value){
                    node.parent.right = null;
                } else {
                    node.parent.left = null;
                }
            }
        } else if (node.hasOnlyLeftChild()){
            if (node == this.root){
                node.left.parent = null;
                this.root = node.left;
            } else {
                if (node.value > node.parent.value){
                    node.parent.right = node.left;
                    node.left.parent = node.parent;
                } else {
                    node.parent.left = node.left;
                    node.left.parent = node.parent;
                }
                
            }
        } else if (node.hasOnlyRightChild()){
            if (node == this.root){
                node.right.parent = null;
                this.root = node.right;
            } else {
                if (node.value > node.parent.value){
                    node.parent.right = node.right;
                    node.right.parent = node.parent;
                } else {
                    node.parent.left = node.right;
                    node.right.parent = node.parent;
                }
                
            }
        } else {
            Node sucessor = sucessor(node);
            int valor = sucessor.value;
            remove(sucessor);
            node.value = valor;
        }
    }

    public int height(Node node){
        if(node == null) return -1;
        else return 1 + Math.max(height(node.left), height(node.right));
    }

    public int height(){
        return height(this.root);
    }

    public void remove(int integer){
        Node node = search(integer);
        if (node != null){
            remove(node);
            this.size--;
        }
    }


    public int size(){
        return this.size;
    }

    public ArrayList<Integer> bfs() {
        ArrayList<Integer> list = new ArrayList<Integer>();
        Deque<Node> queue = new LinkedList<Node>();
        
        if (!isEmpty()) {
            queue.addLast(this.root);
            while (!queue.isEmpty()) {
                Node current = queue.removeFirst();
                
                list.add(current.value);
                
                if(current.left != null) 
                    queue.addLast(current.left);
                if(current.right != null) 
                    queue.addLast(current.right);   
            }
        }
        return list;
    }
}

class Node {
    int value;
    Node left;
    Node right;
    Node parent;

    Node(int v){
        this.value = v;
    }

    public boolean hasOnlyLeftChild(){
        return (this.left != null && this.right == null);
    }
    public boolean hasOnlyRightChild(){
        return (this.left == null && this.right != null);
    }
    public boolean isLeaf(){
        return (this.left == null && this.right == null);
    }
}