/**
* Subclasse Moto
*/
public class Moto extends Veiculo {
	private boolean temSidecar;
	
	public Moto(String marca, String modelo, String cor, int ano, boolean temSidecar) {
		super(marca, modelo, cor, ano);
		
		this.temSidecar = temSidecar;
	}

	public boolean getTemSidecar() {
		return temSidecar;
	}

	public void setTemSidecar(boolean temSidecar) {
		this.temSidecar = temSidecar;
	}

	@Override
	public void exibirDetalhes() {
		System.out.println("Veículo: Moto");
		super.exibirDetalhes();
		// Polimorfismo no exibirDetalhes()
		System.out.println("Tem sidecar: " + (getTemSidecar() ? "Sim" : "Não"));
		System.out.println();
	}
}