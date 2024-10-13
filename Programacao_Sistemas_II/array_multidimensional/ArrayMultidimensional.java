package array_multidimensional;

import java.util.Scanner;

public class ArrayMultidimensional {
    // Control Global Variables
    public static boolean stopProgram = false;

    public static final String[][] myArray = {
        {"Java", "Eclipse", "NetBeans", "IntelliJ"},
        {"Python", "Flask", "Django", "PyCharm"},
        {"C", "Dev-C++", "Code::Blocks"}
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Keep a single Scanner instance
        while (!stopProgram) {
            menu(scanner);
        }
        scanner.close(); // Close scanner after program ends
    }

    // Menu
    public static void menu(Scanner scanner) {
        System.out.println("Escolha uma Opção para Manipular um Array Multidimensional 3x4");
        System.out.println();
        System.out.println("1. Ver o array");
        System.out.println("2. Ver uma linha do array");
        System.out.println("3. Ver uma coluna do array");
        System.out.println("4. Buscar por um elemento no array");
        System.out.println();
        System.out.print("Opção: ");
        
        int option = scanner.nextInt();
        scanner.nextLine(); // Clear the buffer

        switch (option) {
            case 1 -> printArray(myArray);
            case 2 -> {
                System.out.print("Informe o número da linha: ");
                int row = scanner.nextInt();
                scanner.nextLine(); // Clear the buffer
                printRow(myArray, row - 1);
            }
            case 3 -> {
                System.out.print("Informe o número da coluna: ");
                int column = scanner.nextInt();
                scanner.nextLine(); // Clear the buffer
                printColumn(myArray, column - 1);
            }
            case 4 -> {
                System.out.print("Informe o nome do elemento que gostaria de buscar no array: ");
                String element = scanner.nextLine();
                searchElement(element, myArray);
            }
            default -> System.out.println("Opção inválida.");
        }
        continueProgram(scanner);
    }

    public static void continueProgram(Scanner scanner) {
        System.out.print("Deseja continuar (s/n)? ");
        char answer = scanner.next().charAt(0);
        stopProgram = answer == 'n' || answer == 'N';
    }

    public static void printArray(String[][] array) {
        for (String[] row : array) {
            System.out.println("____________________");
            for (String element : row) {
                System.out.println(element);
            }
        }
    }

    public static void printColumn(String[][] array, int column) {
        if (column < 0 || column >= array[0].length) {
            System.out.println("Coluna inválida.");
            return;
        }
        for (String[] row : array) {
            if (column < row.length) { // Handle jagged arrays safely
                System.out.println(row[column]);
            }
        }
    }

    public static void printRowAux(String[] row) {
        for (String element : row) {
            System.out.print(element + " ");
        }
        System.out.println(); // Move to a new line after printing the row
    }

    public static void printRow(String[][] array, int row) {
        if (row < 0 || row >= array.length) {
            System.out.println("Linha inválida.");
            return;
        }
        printRowAux(array[row]);
    }

    public static void searchElement(String element, String[][] array) {
        boolean found = false;

        for (int i = 0; i < array.length && !found; i++) {
            for (int j = 0; j < array[i].length; j++) {
                if (element.equals(array[i][j])) {
                    System.out.println("Linha correspondente ao elemento '" + element + "':");
                    printRowAux(array[i]); // Call helper function to print the row to print the matching row
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            System.out.println("Elemento '" + element + "' não encontrado.");
        }
    }
}
