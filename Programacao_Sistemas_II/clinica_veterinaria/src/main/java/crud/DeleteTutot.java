package crud;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import model.Tutor;

public class DeleteTutot {

	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
		EntityManager em = emf.createEntityManager();
		
		Tutor tutor = em.find(Tutor.class, 1L);
		
		if (tutor != null) {
			em.getTransaction().begin();
			em.remove(tutor);
			em.getTransaction().commit();
		}
		
		em.close();
		emf.close();


	}

}
