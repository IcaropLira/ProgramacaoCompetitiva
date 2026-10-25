/**
 * Laboratório de Programação 2 - Lab 1
 * 
 * @author Ícaro Pinto Lira - 202550019984
*/

import java.util.*;

public class Wally {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            boolean achou = false;
            String linha = sc.nextLine();
            if (linha.equals("wally")){ 
                break; 
            }
            String[] nomes = linha.split(" ");
            for (int i = nomes.length - 1; i >= 0; i--) {
                if (nomes[i].length() == 5){
                    System.out.println(nomes[i]);
                    achou = true;
                    break;
                }
            }
            if (!achou){
                System.out.println("?");
            }

        }

    }
    
}
