package adivinha.numero;

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

/**
 * Atividade 1 - Programação de Sistemas I
 * Implementação do Jogo de Adivinhação de Números em java.
 * 
 * REQUISITOS FUNCIONAIS:
    * Escolha do Intervalo: o jogador pode definir o intervalo de números, dentro do qual um número deve ser adivinhado
    * Geração de Números Aleatórios: o programa deve gerar um número aleatório no intervalo definido.
    * Entrada do Jogador: permitir que o jogador insira tentativas para adivinhar o número.
    * Fornecimento de Dicas: informar ao jogador se o número adivinhado é maior, menor ou igual ao número gerado.
    * Contagem de Tentativas: manter um contador de tentativas até o acerto.
    * Opção de Sair: permitir que o jogador encerre o jogo a qualquer momento.
    * Mensagem de Encerramento: exibir uma mensagem de encerramento, informando o número de tentativas realizadas.
 * 
 * REQUISITOS TÉCNICOS
    * Uso de Estruturas de Controle: implementar loops e condicionais para gerenciar o fluxo do jogo.
    * Geração de Números Aleatórios: utilizar a classe ‘Random’ para gerar o número secreto.
    * Tratamento de Exceções: incluir tratamento para entradas inválidas (por exemplo, caracteres não numéricos).
    * Interação com o Usuário: exibir mensagens claras e informativas para guiar o jogador.
 * 
 */
public class AdivinhaNumero {

	// Defining constants to manipulate colors in terminal output
	private static final String ANSI_GREEN = "\033[32m";
	private static final String ANSI_RED = "\u001B[31m";
    private static final String ANSI_BLUE = "\033[34m";
    private static final String ANSI_PURPLE = "\033[38;2;235;103;247m";
    private static final String ANSI_YELLOW = "\033[93m";
	private static final String ANSI_RESET = "\u001B[0m";

    // Método Principal
    public static void main(String[] args) {
        // Variables definition
        Scanner scanner = new Scanner(System.in);
        boolean getOutOfGame = false;
        int player = 0, computer, minNumber = 1, maxNumber = 100;
        int counter = 0;
        char chooseRange, playerDecision = 's';
        Random random = new Random();

        // Game presentation
        System.out.println(ANSI_PURPLE + "        JOGO DA ADIVINHAÇÃO DE NÚMERO" + ANSI_RESET);
        System.out.println("");
        System.out.println("Regras do jogo:");
        System.out.printf(
                "\t1.Por padrão o computador escolhe um número aleatório entre 1 e 100 para que você possa adivinhar esse número.\n");
        System.out.printf(
                "\t2.Durante seus palpites, o computador dará dicas se o número informado por você está acima ou abaixo do número escolhido por ele.\n");
        System.out.printf(
                "\t3.Você pode escolher o limite inferior e superior do intervalo. Por exemplo, se você escolher 1 e 10, o computador irá escolher um número entre 1 e 10.\n\n");

        // Ask if the user wants to choose the range
        System.out.println(ANSI_YELLOW + "Gostaria de escolher os limites do intervalo? [s/n]" + ANSI_RESET);
        chooseRange = getValidInput(scanner);

        if (chooseRange == 's' || chooseRange == 'S') {
            System.out.println(ANSI_YELLOW + "Informe o limite inferior do intervalo:" + ANSI_RESET);
            minNumber = getValidMinNumber(scanner);
            System.out.println(ANSI_YELLOW + "Informe o limite superior do intervalo:" + ANSI_RESET);
            maxNumber = getValidMaxNumber(scanner);
        }

        // Random number between minNumber and maxNumber
        computer = random.nextInt(maxNumber) + 1;
        // Ask for user's guess
        System.out.println(ANSI_YELLOW + "Tente adivinhar qual número eu escolhi entre " + minNumber + " e " + maxNumber + ANSI_RESET);

        
        do {
            player = getValidGuess(scanner);  // get valid guess from user
            counter++;

            if (player == computer) {
                getOutOfGame = true;
                System.out.println(ANSI_GREEN + "Parabéns. Você acertou o número " + computer + " em " + counter + " tentativa(s)." + ANSI_RESET);
                System.out.println(ANSI_YELLOW + "Fim de Jogo!" + ANSI_RESET);

            } else if (player > computer) {
                System.out.println(ANSI_RED + "Errou! Tente um número menor que " + player + ANSI_RESET);
            } else {
                System.out.println(ANSI_RED + "Errou! Tente um número maior que " + player + ANSI_RESET);
            }

            // Ask if the player wants to continue playing
            if (!getOutOfGame) {
                System.out.println(ANSI_YELLOW + "Continuar jogando? [s/n]" + ANSI_RESET);
                playerDecision = getValidInput(scanner);
                if (playerDecision == 's' || playerDecision == 'S') {
                    System.out.println(ANSI_YELLOW + "Digite outro número" + ANSI_RESET);
                } else {
                    System.out.println(ANSI_BLUE + "Você fez " + counter + " tentativa(s). Até a próxima." + ANSI_RESET);
                }
            }

        } while (!getOutOfGame && (playerDecision == 's' || playerDecision == 'S'));
        scanner.close();
    }

    // Method to handle valid input for 's' or 'n'
    public static char getValidInput(Scanner scanner) {
        char input;
        do {
            input = scanner.next().charAt(0);
            if (input != 's' && input != 'S' && input != 'n' && input != 'N') {
                System.out.println(ANSI_YELLOW + "Entrada inválida. Por favor, digite 's' para sim ou 'n' para não." + ANSI_RESET);
            }
        } while (input != 's' && input != 'S' && input != 'n' && input != 'N');
        return input;
    }

    // Method to handle valid input for the max an min numbers
    public static int getValidMaxNumber(Scanner scanner) {
        int maxNumber = 0;
        boolean validInput = false;
        while (!validInput) {
            try {
                maxNumber = scanner.nextInt();
                if (maxNumber > 1) {
                    validInput = true;
                } else {
                    System.out.println(ANSI_YELLOW + "O número máximo deve ser maior que 1. Por favor, tente novamente." + ANSI_RESET);
                }
            } catch (InputMismatchException e) {
                System.out.println(ANSI_YELLOW + "Entrada inválida. Por favor, insira um número inteiro válido." + ANSI_RESET);
                scanner.next();  // Clear invalid input
            }
        }
        return maxNumber;
    }
    public static int getValidMinNumber(Scanner scanner) {
        int minNumber = 0;
        boolean validInput = false;
        while (!validInput) {
            try {
                minNumber = scanner.nextInt();
                if (minNumber > 0) {
                    validInput = true;
                } else {
                    System.out.println(ANSI_YELLOW + "O número mínimo deve ser maior que 0. Por favor, tente novamente." + ANSI_RESET);
                }
            } catch (InputMismatchException e) {
                System.out.println(ANSI_YELLOW + "Entrada inválida. Por favor, insira um número inteiro válido." + ANSI_RESET);
                scanner.next();  // Clear invalid input
            }
        }
        return minNumber;
    }

    // Method to handle valid guess input
    public static int getValidGuess(Scanner scanner) {
        int guess = 0;
        boolean validInput = false;
        while (!validInput) {
            try {
                guess = scanner.nextInt();
                validInput = true;
            } catch (InputMismatchException e) {
                System.out.println(ANSI_YELLOW + "Entrada inválida. Por favor, insira um número inteiro." + ANSI_RESET);
                scanner.next(); // Clear invalid input
            }
        }
        return guess;
    }
}
