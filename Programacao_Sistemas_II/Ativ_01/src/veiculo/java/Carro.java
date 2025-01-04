/**
* Subclasse Moto
*/
public class Carro extends Veiculo {
	private int numeroDePortas;

	Carro(String marca, String modelo, String cor, int ano, int numeroDePortas) {
		super(marca, modelo, cor, ano);

		this.numeroDePortas = numeroDePortas;
	}

	public int getNumeroDePortas() {
		return this.numeroDePortas;
	}
	
	@Override
	public void exibirDetalhes() {
		System.out.println("Veículo: Carro");
		// Chama o método exibirDetalhes() a partir da classe Veiculo
		super.exibirDetalhes();
		// Polimorfismo no método exibirDetalhes()
		System.out.println("Número de portas: " + getNumeroDePortas());
		System.out.println();
	}
	
	
}
