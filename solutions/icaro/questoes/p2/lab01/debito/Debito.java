/**
 * Laboratório de Programação 2 - Lab 1
 * 
 * @author Ícaro Pinto Lira - 202550019984
 */

import java.util.Scanner;

public class Debito {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        float dinheiro = sc.nextFloat();
        sc.nextLine();
        String tipo = sc.nextLine();
        if (tipo.equals("credito")){
            String parcelamento = sc.nextLine();
            if (parcelamento.equals("n")){
                System.out.println(dinheiro + " REAIS NO CREDITO (DIRETO)");
            }
            else {
                int parcelas = sc.nextInt();
                sc.nextLine();
                float total = dinheiro / parcelas;
                System.out.println(parcelas + " PARCELAS DE " + total +  " REAIS");
            }
        }
        else {
            System.out.println(dinheiro + " REAIS NO DEBITO");
        }
        }    
}
