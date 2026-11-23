package eda;

import java.util.ArrayList;
import java.util.Arrays;

public class BSTTest {

    static void assertEquals(Object esperado, Object obtido) {
        if (!esperado.equals(obtido)) {
            throw new AssertionError("Esperado: " + esperado + " mas veio: " + obtido);
        }
    }

    static ArrayList<Integer> lista(Integer... v) {
        return new ArrayList<Integer>(Arrays.asList(v));
    }

    public static void main(String[] args) {
        BST bst = new BST();
        for (int x : new int[]{85, 49, 97, 7, 53, 93, 51, 81, 65, 55}) {
            bst.add(x);
        }

        assertEquals(lista(85, 49, 97, 7, 53, 93, 51, 81, 65, 55), bst.bfs());

        bst.remove(85);
        assertEquals(lista(93, 49, 97, 7, 53, 51, 81, 65, 55), bst.bfs());

        bst.remove(93);
        assertEquals(lista(97, 49, 7, 53, 51, 81, 65, 55), bst.bfs());

        bst.remove(7);
        assertEquals(lista(97, 49, 53, 51, 81, 65, 55), bst.bfs());

        bst.remove(97);
        assertEquals(lista(49, 53, 51, 81, 65, 55), bst.bfs());

        bst.remove(53);
        assertEquals(lista(49, 55, 51, 81, 65), bst.bfs());
        assertEquals(5, bst.size());

        bst.remove(81);
        assertEquals(lista(49, 55, 51, 65), bst.bfs());

        bst.remove(51);
        assertEquals(lista(49, 55, 65), bst.bfs());

        bst.remove(55);
        assertEquals(lista(49, 65), bst.bfs());

        bst.remove(49);
        assertEquals(lista(65), bst.bfs());

        bst.remove(65);
        assertEquals(lista(), bst.bfs());

        bst.add(65);
        assertEquals(lista(65), bst.bfs());
        assertEquals(1, bst.size());

        System.out.println("Todos os testes passaram!");
    }
}