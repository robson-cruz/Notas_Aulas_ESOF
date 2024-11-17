package crud;

import DAO.DAO;
import model.Animal;

public class ReadAnimal {

	public static void main(String[] args) {
		DAO<Animal> dao = new DAO<>(Animal.class);
		
		Animal animal = dao.getDataById(1L);
		System.out.println(animal);

	}

}
