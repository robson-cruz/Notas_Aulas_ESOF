/**
* Atividade 1 - prorgamação de Sistemas II
* Construção de Estrutura de Classes com Herança em Java
*/

public class Main {
    public static void main(String[] args) {
        // Instanciando um objeto da classe Carro
        Carro carro = new Carro("Fiat", "Uno", "Branco", 2010, 4);
        carro.exibirDetalhes();
      
        // Instanciando dois objetos da classe Moto
        Moto moto = new Moto("Honda", "CBR 600", "Vermelho", 1992, true);
        moto.exibirDetalhes();
        Moto moto2 = new Moto("Honda", "CBR 750F", "Azul", 1992, true);
        moto.exibirDetalhes();

    }
}