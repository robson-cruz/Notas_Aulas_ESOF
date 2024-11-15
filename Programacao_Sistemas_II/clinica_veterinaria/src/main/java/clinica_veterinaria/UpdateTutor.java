package clinica_veterinaria;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

public class UpdateTutor {

	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
		EntityManager em = emf.createEntityManager();
		
			
		em.getTransaction().begin();
		
		Tutor tutor = em.find(Tutor.class, 4L);
		tutor.setNome("Izildinha Saruê");
		
		em.merge(tutor);
		
		em.getTransaction().commit();
		
		em.close();
		emf.close();

	}

}
