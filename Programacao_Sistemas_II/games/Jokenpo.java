package jokenpo;

import java.util.Random;
import java.util.Scanner;

public class Jokenpo {

    private static final String ANSI_RED = "\u001B[31m";
    private static final String ANSI_RESET = "\u001B[0m";
    private static final String ANSI_GREEN = "\033[32m";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char continue_play;

        do {
            System.out.println("----------------------");
            System.out.println("_______JoKenPô________");
            System.out.println("");
            System.out.println(" 1. Pedra");
            System.out.println(" 2. Papel");
            System.out.println(" 3. Tesoura");
            System.out.println("----------------------");
            System.out.println("");

            int jogador, maquina;

            Random random = new Random();
            maquina = random.nextInt(3) + 1;

            System.out.println("Escolha sua opção: ");
            jogador = scanner.nextInt();

            if (jogador < 1 || jogador > 3) {
                System.out.println("Opção Inválida!");
            } else {
                // Exibindo a escolha da máquina
                switch (maquina) {
                    case 1:
                        System.out.println("Computador: Pedra");
                        break;
                    case 2:
                        System.out.println("Computador: Papel");
                        break;
                    case 3:
                        System.out.println("Computador: Tesoura");
                        break;
                }

                // Exibindo a escolha do jogador
                switch (jogador) {
                    case 1:
                        System.out.println("Você: Pedra");
                        break;
                    case 2:
                        System.out.println("Você: Papel");
                        break;
                    case 3:
                        System.out.println("Você: Tesoura");
                        break;
                }

                // Lógica para determinar o vencedor
                if (jogador == maquina) {
                    System.out.println("----------------------");
                    System.out.println("EMPATOU!!!");
                    System.out.println("----------------------");
                } else if ((jogador == 1 && maquina == 3) ||  // Pedra vence Tesoura
                           (jogador == 2 && maquina == 1) ||  // Papel vence Pedra
                           (jogador == 3 && maquina == 2)) {  // Tesoura vence Papel
                    System.out.println("----------------------");
                    System.out.println(ANSI_GREEN + "Você Ganhou!!" + ANSI_RESET);
                    System.out.println("----------------------");
                } else {
                    System.out.println("----------------------");
                    System.out.println(ANSI_RED + "O Computador Ganhou!!" + ANSI_RESET);
                    System.out.println("----------------------");
                }
            }

            System.out.println("Continua: [s/n]?");
            System.out.println("----------------------");
            continue_play = scanner.next().charAt(0);

        } while (continue_play == 's' || continue_play == 'S');

        scanner.close();
    }
}
