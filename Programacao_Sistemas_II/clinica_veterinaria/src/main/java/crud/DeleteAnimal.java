package crud;

import DAO.DAO;
import model.Animal;

public class DeleteAnimal {

	public static void main(String[] args) {
		DAO<Animal> dao = new DAO<>(Animal.class);
		
		System.out.println(dao.deleteById(3L));
		dao.closeEM();

	}

}
