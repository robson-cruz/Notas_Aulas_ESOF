import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * MAPA - ESOFT - PROGRAMAÇÃO DE SISTEMAS I - 54_2024
 * CRIAÇÃO DO JOGO DA VELHA EM JAVA
 */
public class TicTacToe {
    // Definição de constantes para manipular cores na saída do terminal
    private static final String ANSI_RED = "\u001B[31m";
    private static final String ANSI_RESET = "\u001B[0m";
    private static final String ANSI_GREEN = "\033[32m";
    private static final String ANSI_YELLOW = "\033[93m";

    // Variável global para controlar o estado do jogo
    private static boolean stopGame = false;

    /**
     * @param args
     */
    public static void main(String[] args) {
        // Leitura de arquivo como o nome do jogo
        String pathFile = "./ticTacToe.txt";
        try(BufferedReader reader = new BufferedReader(new FileReader(pathFile))) {
            String fileLine;
            // Lê o arquivo linha por linha
            while ((fileLine = reader.readLine()) != null) {
                // Imprime cada linha no console
                System.out.println(fileLine);
            }
        } catch(IOException e) {
            e.printStackTrace();
        }

        Scanner scanner = new Scanner(System.in);
        boolean playAgain = true;

        while (playAgain) {
            startGame(scanner);

            // Após o jogo terminar, perguntar se querem jogar novamente
            System.out.println("Desejam jogar novamente? (s/n)");
            char resposta = scanner.next().charAt(0);
            if (resposta == 'n' || resposta == 'N') {
                playAgain = false;
                System.out.println("Obrigado por jogar!\n");
            } else {
                restartGame();
            }
        }
    }
    
    // Método para iniciar o jogo
    /**
     * @param scanner
     */
    public static void startGame(Scanner scanner) {
        // Definição de variáveis
        int currentPlayer;
        int x, y;
        int counter = 0;
        char[][] matrizJogo = new char[3][3];

        System.out.println("\n\n\t1. Escolham quem será o jogador 1 e o jogador 2");
        System.out.println("\t2. O jogador 1 é representado pelo caractere 'X' e o jogador 2 pelo caractere 'O'");
        System.out.println("\t3. Definam qual jogadorirá iniciar.");
        System.out.println("\t4. Na sua vez cada jogador deve informar a linha e coluna onde irá jogar.\n");
        System.out.println("Quem iniciará jogando? [1/2]?");

        currentPlayer = scanner.nextInt();
        
        mostrarMatrizPadrao(matrizJogo);
        
        while (counter < 9 && !stopGame) {
            if (currentPlayer == 1) {
                System.out.println("Jogar 1: insira a linha e coluna onde irá jogar:");
                System.out.println("Jogar 1: insira o número da linha e tecle ENTER");
                x = scanner.nextInt() - 1;
                System.out.println("Jogar 1: insira o número da coluna e tecle ENTER");
                y = scanner.nextInt() - 1;
                if (x >= 0 && x < 3 && y >= 0 && y < 3 && matrizJogo[x][y] == '-') {
                    inserirJogada(matrizJogo, 'X', x, y);
                    mostrarMatriz(matrizJogo);
                    counter ++;
                    checkWin(matrizJogo);
                    currentPlayer = 2; // Alterna para o jogador 2
                } else {
                    System.out.println(ANSI_RED + "Posição inválida. Tente novamente." + ANSI_RESET);
                }
                
            } else {
                System.out.println("Jogar 2: insira a linha e coluna onde irá jogar:");
                System.out.println("Jogar 2: insira o número da linha e tecle ENTER");
                x = scanner.nextInt() - 1;
                System.out.println("Jogar 2: insira o número da coluna e tecle ENTER");
                y = scanner.nextInt() - 1;
                if (x >= 0 && x < 3 && y >= 0 && y < 3 && matrizJogo[x][y] == '-') {
                    inserirJogada(matrizJogo, 'O', x, y);
                    mostrarMatriz(matrizJogo);
                    counter ++;
                    checkWin(matrizJogo);
                    currentPlayer = 1; // Alterna para o jogador 1
                } else {
                    System.out.println(ANSI_RED + "Posição inválida. Tente novamente." + ANSI_RESET);
                }
            }
        }
        
        if (!stopGame) {
            System.out.println(ANSI_YELLOW + "O jogo empatou!" + ANSI_RESET);
        }
    }
    
    // Método para reiniciar o jogo
    public static void restartGame() {
        stopGame = false; // Reseta o status do jogo
    }

    // Método para mostrar a matriz do jogo vazia
    /**
     * @param matriz
     */
    public static void mostrarMatrizPadrao(char matriz[][]) {
        for (int linha = 0; linha < matriz.length; linha++) {
            for (int coluna = 0; coluna < matriz[linha].length; coluna++) {
                matriz[linha][coluna] = '-';
            }
        }
        System.out.println();

        mostrarMatriz(matriz);
    }

    // Método para inserir dados na matriz
    /**
     * @param matriz
     * @param caractere
     * @param linha
     * @param coluna
     */
    public static void inserirJogada(char matriz[][], char caractere, int linha, int coluna) {
        if (matriz[linha][coluna] == 'O' | matriz[linha][coluna] == 'X') {
            System.out.println(ANSI_RED + "Jogada irregular, tente uma posição ainda não ocupada." + ANSI_RESET);
        } else {
            matriz[linha][coluna] = caractere;
            System.out.println("Jogada realizada com sucesso.");
        }
    }

    // Método para mostrar a matriz atualizada
    /**
     * @param matriz
     */
    public static void mostrarMatriz(char matriz[][]) {
        System.out.println();
        System.out.println();

        for (int linha = 0; linha < matriz.length; linha++) {
            for (int coluna = 0; coluna < matriz[linha].length; coluna++) {
                System.out.print("\t" + matriz[linha][coluna] + "  ");
            }
            System.out.println(); // Pula para a próxima linha após imprimir uma linha completa
        }
        System.out.println();
    }

    // Método para checar Vitória
    /**
     * @param matriz
     */
    public static void checkWin(char matriz[][]) {
        
        // Definindo as possíveis combinações de vitória
        char[] diagonal1 = {matriz[0][0], matriz[1][1], matriz[2][2]};
        char[] diagonal2 = {matriz[2][0], matriz[1][1], matriz[0][2]};
        char[] column1 = {matriz[0][0], matriz[1][0], matriz[2][0]};
        char[] column2 = {matriz[0][1], matriz[1][1], matriz[2][1]};
        char[] column3 = {matriz[0][2], matriz[1][2], matriz[2][2]};
        char[] row1 = {matriz[0][0], matriz[0][1], matriz[0][2]};
        char[] row2 = {matriz[1][0], matriz[1][1], matriz[1][2]};
        char[] row3 = {matriz[2][0], matriz[2][1], matriz[2][2]};

        // Criando a matriz com todas as combinações de vitória
        char[][] winMatrix = {
            diagonal1, diagonal2,
            column1, column2, column3,
            row1, row2, row3
        };

        // Verificando se algum dos arrays de vitória tem todos os elementos iguais
        for (int i = 0; i < winMatrix.length; i++) {
            if (checkArrays(winMatrix[i])) {
                System.out.println(ANSI_GREEN + winMatrix[i][0] + " venceu.\n" + ANSI_RESET);
                stopGame = true;
                return; // Interrompe a verificação após encontrar um vencedor
            }
        }
    }

    // Método auxiliar para verificar se todos os elementos do array são iguais
    /**
     * @param array
     * @return
     */
    public static boolean checkArrays(char[] array) {
        if (array.length == 0 || array[0] == '-') { // Exclui células vazias (representadas por '-')
            return false;
        }

        char firstElement = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] != firstElement) {
                return false;
            }
        }

        return true;
    }
}
