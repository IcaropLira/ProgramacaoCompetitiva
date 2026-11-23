package bst;

import java.util.*;

public class BST {
    private Node root;
    private int size;

    public boolean isEmpty(){
        return this.root == null;
    }

    public void add(int element){
        this.size += 1;
        if (isEmpty()){
            this.root = new Node(element);
        } else {
            aux = this.root;
            while (aux != null) {
                
                if (element > aux.value){
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
        if(node.left != null){
            return max(node.left);
        }
        else {
            Node aux = node.parent;
            while (aux.parent != null && aux.value > node.value) {
                aux = aux.parent;
            }

            return aux;
        }
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
}