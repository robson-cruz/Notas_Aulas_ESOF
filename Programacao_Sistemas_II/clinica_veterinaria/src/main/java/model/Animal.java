package model;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity
public class Animal {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;
	private String nome;
	private String raca;
	private Float peso;
	private String especie;
	private String dataNascimento;
	
	public Animal() {
		super();
	}

	public Animal(String nome, String raca, Float peso, String especie, String dataNascimento) {
		super();
		this.nome = nome;
		this.raca = raca;
		this.peso = peso;
		this.especie = especie;
		this.dataNascimento = dataNascimento;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getRaca() {
		return raca;
	}

	public void setRaca(String raca) {
		this.raca = raca;
	}

	public Float getPeso() {
		return peso;
	}

	public void setPeso(Float peso) {
		this.peso = peso;
	}

	public String getEspecie() {
		return especie;
	}

	public void setEspecie(String especie) {
		this.especie = especie;
	}

	public String getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(String dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	@Override
	public String toString() {
		return "Animal [id=" + id + ", nome=" + nome + ", raca=" + raca + ", peso=" + peso + ", especie=" + especie
				+ ", dataNascimento=" + dataNascimento + "]";
	}
	
}
