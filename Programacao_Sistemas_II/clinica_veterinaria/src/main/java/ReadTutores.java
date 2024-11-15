import java.util.List;

import clinica_veterinaria.Tutor;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.TypedQuery;

public class ReadTutores {

	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
		EntityManager em = emf.createEntityManager();
		
		String jpql = "select t from Tutor t";
		TypedQuery<Tutor> query = em.createQuery(jpql, Tutor.class);
		query.setMaxResults(10);
		// Mostrar o resultado da query de 10 em 10 registros
		// query.setFirstResult(10);
		
		List<Tutor> tutores = query.getResultList();
		for (Tutor tutor : tutores) {
			System.out.println(tutor);
		}
		
		em.close();
		emf.close();

	}

}
