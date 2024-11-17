package crud;

import DAO.DAO;
import model.Animal;

public class CreateAnimal {

	public static void main(String[] args) {
		/*
		// Incluir um animal no banco de dados
		Animal animal1 = new Animal("Bob", "Shitzu", 5.2f, "canica", "2020-12-01");
		
		DAO<Animal> dao = new DAO<>(Animal.class);
		dao.incluirTransacionalo(animal1);
		*/
		
		// incluir vários animais no banco de dados
		Animal animal2 = new Animal("Thor", "Fila", 65.2f, "canica", "2021-12-11");
		Animal animal3 = new Animal("Nina", "Pit Bull", 44.0f, "canica", "2011-02-01");
		Animal animal4 = new Animal("Max", "Bull Dog", 41.0f, "canica", "2018-03-01");
		
		DAO<Animal> dao = new DAO<>(Animal.class);
		dao.abrirTransacao();
		dao.incluirE(animal2);
		dao.incluirE(animal3);
		dao.incluirE(animal4);
		dao.comitarTransacao();
		dao.closeEM();
	}

}
