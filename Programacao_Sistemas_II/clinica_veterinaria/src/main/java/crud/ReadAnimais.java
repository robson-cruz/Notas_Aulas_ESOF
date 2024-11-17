package crud;

import java.util.List;

import DAO.DAO;
import model.Animal;

public class ReadAnimais {

	public static void main(String[] args) {
		DAO<Animal> dao = new DAO<>(Animal.class);
		
		List<Animal> animais = dao.obterTodos(10, 0);
		
		for (Animal animal: animais) {
			System.out.println(animal.toString());
		}
	}

}
