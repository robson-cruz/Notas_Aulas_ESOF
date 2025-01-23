/**
* Classe pai
*/
public class Veiculo {
	private String marca;
	private String modelo;
	private String cor;
	private int ano;

	// Método Construtor para inicializar os atributos marca, modelo, e ano
	Veiculo(String marca, String modelo, String cor, int ano) {
		this.marca = marca;
		this.modelo = modelo;
		this.cor = cor;
		this.ano = ano;
	}

	// Getters e Setters
	public String getMarca() {
		return this.marca;
	}
	
	public String getModelo() {
		return this.modelo;
	}

	public String getCor() {
		return this.cor;
	}
	
	public int getAno() {
		return this.ano;
	}
	
	public void setMarca(String marca) {
		this.marca = marca;
	}
	
	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public void setCor(String cor) {
		this.cor = cor;
	}
	
	public void setAno(int ano) {
		this.ano = ano;
	}
	
	// Método para exibir os detalhes do veículo
	public void exibirDetalhes() {
		String strVeiculo = "Marca: " + getMarca() + "\nModelo: " + getModelo() +  "\nCor: " + getCor() + "\nAno: " + getAno();;
	
		System.out.println(strVeiculo);
	}
}