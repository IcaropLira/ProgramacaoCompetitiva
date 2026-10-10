/**
 * Laboratório de Programação 2 - Lab 1
 * 
 * @author Ícaro Pinto Lira - 202550019984
*/

import java.util.*;

public class Notas {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int maior = 0;
        int menor = 1000;
        int c = 0;
        int acima = 0;
        int abaixo = 0;
        int total = 0;
        while (true){
            String entrada = sc.nextLine();
            if (entrada.equals("-")){
                break;
            }
            String[] partes = entrada.split(" ");
            int num = Integer.parseInt(partes[1]);
            if (num >= 700){
                acima++;
            }
            else{
                abaixo++;
            }
            if (num > maior){
                maior = num;
            }
            if (num < menor){
                menor = num;
            }
            total += num;
            c++;
        }
        int media = (int) total / c;
        System.out.println("maior: " + maior);
        System.out.println("menor: " + menor);
        System.out.println("media: " + media);
        System.out.println("acima: " + acima);
        System.out.println("maior: " + abaixo);
    }
}
