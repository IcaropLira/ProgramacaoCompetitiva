/**
 * Laboratório de Programação 2 - Lab 1
 * 
 * @author Ícaro Pinto Lira - 202550019984
 */

import java.util.Scanner;

public class Sorvete{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int pos1 = sc.nextInt();
		int vel1 = sc.nextInt();
		int pos2 = sc.nextInt();
		int vel2 = sc.nextInt();
		int tempo = sc.nextInt();
		
		int tot1 = pos1 + (vel1 * tempo);
		int tot2 = pos2 + (vel2 * tempo);
		int fin = Math.abs(tot1 - tot2);
		System.out.println(fin);
			
	}
}
