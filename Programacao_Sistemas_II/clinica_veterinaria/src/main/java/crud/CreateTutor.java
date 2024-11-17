package crud;

import DAO.DAO;
import model.Tutor;

public class CreateTutor {

	public static void main(String[] args) {
		/*
		 * Sem usar DAO
		Tutor t1 = new Tutor("Izildinha Ssaruê", "12312345577", "91 3210-4718", "iza.sarue@email.com");
		
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
		EntityManager em = emf.createEntityManager();
		
		em.getTransaction().begin();;
		em.persist(t1);
		em.getTransaction().commit();
		
		em.close();
		emf.close();
		*/
		
		// Usando DAO
		Tutor tutor2 = new Tutor("Ana Maria", "12332145602", "91 4004-3221", "an.maria@email.com");
		Tutor tutor3 = new Tutor("Marta Ferreira", "92332145602", "91 3231-1221", "ferma@email.com");
		Tutor tutor4 = new Tutor("Joana santos", "12832145601", "91 3210-4787", "santos.jo@email.com");
		
		DAO<Tutor> dao = new DAO<>(Tutor.class);
		dao.abrirTransacao();
		dao.incluirE(tutor2);
		dao.incluirE(tutor3);
		dao.incluirE(tutor4);
		dao.comitarTransacao();
		dao.closeEM();
	}

}
