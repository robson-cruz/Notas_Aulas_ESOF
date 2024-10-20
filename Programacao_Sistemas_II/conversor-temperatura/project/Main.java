import java.util.Scanner;

public class Main {
    /** 
     * Celsius to Fahrenheit
     * Fahrenheit to Celsius
     * 
     * @param args
     */

    public static boolean exitProgram = false;

    public static void main(String args[]) {
        try (Scanner scanner = new Scanner(System.in)) {
            while(!exitProgram) {
                menu(scanner);
            }
        }
    }
    
    /**
     * Menu
     * 
     * @param scanner
     */
    public static void menu(Scanner scanner) {
        System.out.println("Conversor de Temperatura");
        System.out.println("1. Celsius para Fahrenheit");
        System.out.println("2. Fahrenheit para Celsius");
        System.out.println("3. Kelvin para Celsius");
        System.out.println("4. Celsius para Kelvin");
        System.out.print("Opção: ");
        
        int choice;
    
        choice = scanner.nextInt();
        scanner.nextLine();  // Clear the buffer
            
        switch(choice) {
            case 1 -> {
                System.out.print("\nGraus Celsius: ");
                double c = scanner.nextDouble();
                Temperature.celsiusToFahrenheit(c);
            }
            case 2 -> {
                System.out.print("\nGraus Fahrenheit: ");
                double f = scanner.nextDouble();
                Temperature.fahrenheitToCelsius(f);
            }
            case 3 -> {
                System.out.print("\nGraus Kelvin: ");
                double k = scanner.nextDouble();
                Temperature.kelvinToCelsius(k);
            }
            case 4 -> {
                System.out.print("\nGraus Celsius: ");
                double c = scanner.nextDouble();
                Temperature.celsiusToKelvin(c);
            }
            default -> System.out.println("Opção inválida.");
        }
        continueProgram(scanner);
    }

    /**
     * continueProgram method
     * 
     * @param scanner
     */
    public static void continueProgram(Scanner scanner) {
        System.out.print("\nDeseja continuar (s/n)? ");
        char answer = scanner.next().charAt(0);
        exitProgram = answer == 'n' || answer == 'N';
    }
}