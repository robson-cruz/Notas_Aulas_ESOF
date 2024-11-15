package crud;

import clinica_veterinaria.Tutor;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

public class CreateTutor {

	public static void main(String[] args) {
		Tutor t1 = new Tutor("Izildinha Ssaruê", "12312345577", "91 3210-4718", "iza.sarue@email.com");
		
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
		EntityManager em = emf.createEntityManager();
		
		em.getTransaction().begin();;
		em.persist(t1);
		em.getTransaction().commit();
		
		em.close();
		emf.close();

	}

}
