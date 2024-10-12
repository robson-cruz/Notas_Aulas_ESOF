package aula_03;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		double raio;
		
		System.out.println("Calcular Área e Perímetro de Círculos\n");
		System.out.println("Qual o raio do círculo?");
		raio = scanner.nextDouble();
		scanner.close();
		
		System.out.println("*-------------------------------*");
		System.out.println("| Raio: " + raio + "\t\t\t|");
		System.out.println("| Área: " + Circulo.area(raio) + "\t|");
		System.out.println("| Perímetro: " + Circulo.perimetro(raio) + "\t|");
		System.out.println("*-------------------------------*");
		
	}

}
