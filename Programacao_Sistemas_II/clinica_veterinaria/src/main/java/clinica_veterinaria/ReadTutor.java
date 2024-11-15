package clinica_veterinaria;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;


public class ReadTutor {

	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
		EntityManager em = emf.createEntityManager();
		
		Tutor tutor = em.find(Tutor.class, 2L);
		System.out.println(tutor);
		
		em.close();
		emf.close();

	}

}
