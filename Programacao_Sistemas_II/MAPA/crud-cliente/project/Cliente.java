import java.util.ArrayList;
import java.util.Iterator;

public class Cliente {
    private int id;
    private static int contadorId = 0;  // Variável estática para gerar IDs
    private String nome;
    private String email;
    private String telefone;
    private static ArrayList<Cliente> clientes = new ArrayList<>();
    
    // Método construtor
    public Cliente(String nome, String email, String telefone) {
        // Validar Entrada de Dados (Evitar Nulos ou Vazios)
        if (nome == null || nome.isEmpty() || email == null || email.isEmpty()) {
            throw new IllegalArgumentException("Nome e e-mail não podem ser vazios.");
        }

        this.id = ++contadorId;
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
    }
    
    // Getters
    public int getId() {
        return this.id;
    }

    public String getNome() {
        return this.nome;
    }

    public String getEmail() {
        return this.email;
    }

    public String getTelefone() {
        return this.telefone;
    }
    
    // Setters
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    
    /**
     * Método para cadastrar cliente
     * @param cliente
     * @return
     */
    public static boolean cadastrar(Cliente cliente) {
        // Verifica se já existe um cliente com o mesmo e-mail
        for (Cliente c : clientes) {
            if (c.getEmail().equalsIgnoreCase(cliente.getEmail())) {
                System.out.println("Cliente com este e-mail já está cadastrado.");
                return false;
            }
        }
        clientes.add(cliente);
        return true;
    }
    
    /**
     * Método para mostrar um cliente pelo 'id'
     * @param id
     * @return
     */
    public static String mostrarCliente(int id) {
        System.out.println("Executando mostrarCliente para ID: " + id);  // Log para teste
        for (Cliente cliente : clientes) {
            if (cliente.getId() == id) {
                return cliente.toString();
            }
        }
        return "Cliente com ID " + id + " não encontrado.";
    }
    
    /**
     * Método para listar todos os clientes pressentes no ArrayList
     * @return
     */
    public static String mostrarDados() {
        StringBuilder strClientes = new StringBuilder();
        
        for (Cliente cliente : clientes) {
            strClientes.append(cliente).append("\n");
        }
        return strClientes.toString();
    }
    
    /**
     * Método para atualizar os dados de um cliente
     * @param id
     * @param novoNome
     * @param novoEmail
     * @param novoTelefone
     * @return
     */
    public static boolean atualizarCliente(int id, String novoNome, String novoEmail, String novoTelefone) {
        for (Cliente cliente : clientes) {
            if (cliente.getId() == id) {
                cliente.setNome(novoNome);
                cliente.setEmail(novoEmail);
                cliente.setTelefone(novoTelefone);
                return true;
            }
        }
        return false;
    }
    
    /**
     * Método para excluir um cliente
     * @param id
     * @return
     */
    public static boolean deletarCliente(int id) {
        /*
        for (Cliente cliente : clientes) {
            if (cliente.getId() == id) {
                clientes.remove(cliente);
                return true;
            }
        }
        return false;
        */
        Iterator<Cliente> iterator = clientes.iterator();

        while (iterator.hasNext()) {
            Cliente cliente = iterator.next();
            if (cliente.getId() == id) {
                iterator.remove();  // Remoção segura
                return true;
            }
        }
        return false;
    }
    
    // Sobrescrever toString() para mostrar informação do cliente
    @Override
    public String toString() {
        return "=============================\n" +
                "ID: " + id + "\n" +
                "Nome: " + nome + "\n" +
                "Email: " + email + "\n" +
                "Telefone: " + telefone + "\n" +
                "=============================";
    }
}