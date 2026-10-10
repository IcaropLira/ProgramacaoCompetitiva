/**
 * Laboratório de Programação 2 - Lab 1
 * 
 * @author Ícaro Pinto Lira - 202550019984
 */ */

import java.util.*;

public class Media {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String linha = sc.nextLine();
        String[] partes = linha.split(" ");

        int n = partes.length;
        int[] nums = new int[n];
        int soma = 0;

        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(partes[i]);
            soma += nums[i];
        }
        double media = (double) soma / n;
        boolean primeiro = true;

        for (int i = 0; i < n; i++){
            if (nums[i] > media){
                if (!primeiro) System.out.print(" ");
                System.out.print(nums[i]);
                primeiro = false;
            }
        }
        System.out.println(); 

    }
}
