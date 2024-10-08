package tabuada;

import java.util.Scanner;

public class Tabuada {

	public static void main(String[] args) {
		System.out.println("********************************");
		System.out.println("|           TABUADA            |");
		System.out.println("********************************");
		
		int n;
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Qual o Valor da Tabuada [1-10]?");
		System.out.println("********************************");
		n = scanner.nextInt();
		System.out.println("********************************");
		
		for (int i = 1; i < 11; i++) {
			//String str_tab = n + " *  " + i + " = " + n * i;
			//System.out.println(str_tab);
			System.out.printf("\t%2d x %2d = %2d\n", n, i, n*i);
		}
		System.out.println("********************************");
		scanner.close();

	}

}
