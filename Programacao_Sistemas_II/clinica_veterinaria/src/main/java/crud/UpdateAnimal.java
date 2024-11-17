package crud;

import DAO.DAO;
import model.Animal;

public class UpdateAnimal {

	public static void main(String[] args) {
		DAO<Animal> dao = new DAO<>(Animal.class);
		
		// Atualizar o peso do animal de id = 1
		Animal animal = dao.getDataById(1L);
		animal.setPeso(4.2f);
		
		dao.updateData(animal);
		
		dao.closeEM();

	}

}
