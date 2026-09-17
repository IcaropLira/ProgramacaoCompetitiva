/**
 * Laboratório de Programação 2 - Lab 1
 * 
 * @author Ícaro Pinto Lira - 202550019984
 */

import java.util.Scanner;

public class Blitz{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int licenciamento = sc.nextInt();
	       	int carteira = sc.nextInt();
		double alcool = sc.nextDouble();
		
		if (licenciamento < 30 && carteira < 30 && alcool <= 0.05){
			System.out.println("False");
		}
		else {
			System.out.println("True");
		}
	}
}
