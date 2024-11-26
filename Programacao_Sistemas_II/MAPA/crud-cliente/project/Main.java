import java.util.Scanner;

public class Main {
    // Variável global para decisão do usuário quanto a permanecer no programa
    public static boolean sair;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (!sair) {
            menu(scanner);
        }
        scanner.close();
    }
    
    // menu
    /**
     * @param scanner
     */
    public static void menu(Scanner scanner) {
        System.out.println("CRUD CLIENTES\n");
        System.out.println("1. CADASTRAR UM CLIENTE");
        System.out.println("2. CONSULTAR UM CLIENTE");
        System.out.println("3. ATUALIZAR UM CLIENTE");
        System.out.println("4. EXCLUIR UM CLIENTE");
        System.out.println("5. VER TODOS CLIENTES");
        System.out.println();
        System.out.print("Opção: ");
        
        int opcao = scanner.nextInt();
        scanner.nextLine();  // limpar o buffer do teclado
        
        switch(opcao) {
            case 1 -> {
                // Create
                System.out.println("\nNome do Cliente");
                String nome = scanner.nextLine();
                System.out.println("Email do Cliente");
                String email = scanner.nextLine();
                System.out.println("Telefone do Cliente");
                String fone = scanner.nextLine();

                Cliente novoCliente = new Cliente(nome, email, fone);
                Cliente.cadastrar(novoCliente);
                System.out.println("Cliente cadastrado com sucesso!\n");
            }
            
            case 2 -> {
                // Read
                System.out.println("ID do Cliente");

                // Verifique se o usuário realmente forneceu um número válido
                while (!scanner.hasNextInt()) {
                    System.out.println("Por favor, digite um número válido:");
                    scanner.next();  // Descarta a entrada inválida
                }

                int idConsulta = scanner.nextInt();
                scanner.nextLine();
                // Exibi os dados do cliente
                System.out.println(Cliente.mostrarCliente(idConsulta));
            }
            
            case 3 -> {
                // Update
                System.out.println("ID do Cliente");
                int idAtualizar = scanner.nextInt();
                scanner.nextLine();
                System.out.println("Nome do Cliente");
                String novoNome = scanner.nextLine();
                System.out.println("Email do Cliente");
                String novoEmail = scanner.nextLine();
                System.out.println("Telefone do Cliente");
                String novoFone = scanner.nextLine();
                boolean atualizado = Cliente.atualizarCliente(idAtualizar, novoNome, novoEmail, novoFone);
                System.out.println(atualizado ? "Cliente atualizado com sucesso!" : "Cliente não encontrado!");
            }
            
            case 4 -> {
                // Delete
                System.out.println("ID do Cliente");

                while (!scanner.hasNextInt()) {
                    System.out.println("Por favor, digite um número válido:");
                    scanner.next();  // Descarta entrada inválida
                }

                int idExcluir = scanner.nextInt();
                scanner.nextLine();
                
                boolean excluido = Cliente.deletarCliente(idExcluir);
                System.out.println(excluido ? "Cliente excluído com sucesso!" : "Cliente não encontrado!");
            }
            
            case 5 -> {
                System.out.println(Cliente.mostrarDados());
            }
            
            default -> System.out.println("Opção inválida!");
        }
        continuarPrograma(scanner);
    }
    
    /**
     * @param scanner
     */
    public static void continuarPrograma(Scanner scanner) {
        char answer;

        do { 
            System.out.print("\nContinuar no programa (s/n)? ");
            answer = scanner.next().trim().toLowerCase().charAt(0);
        } while (answer != 's' && answer != 'n');

        sair = answer == 'n';
    }
}