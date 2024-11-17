package DAO;

import java.util.List;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.TypedQuery;

public class DAO<E> {
	private static EntityManagerFactory emf;
	private EntityManager em;
	private Class<E> classe;
	
	static {
		try {
			emf = Persistence.createEntityManagerFactory("clinica_veterinaria");
			
		} catch (Exception e) {
			e.getMessage().toString();
		}
	}
	
	// Construtor padrão
	public DAO() {
		this(null);
	}
	
	// Construtor que recebe a classe
	public DAO(Class<E> classe) {
		this.classe = classe;
		em = emf.createEntityManager();
	}
	
	// Open transaction
	public DAO<E> abrirTransacao() {
	    try {
	        if (!em.getTransaction().isActive()) {
	            em.getTransaction().begin();
	        }
	    } catch (Exception e) {
	        e.printStackTrace();
	        throw new RuntimeException("Erro ao abrir transação");
	    }
	    return this;
	}

	
	// Commit transaction
	public DAO<E> comitarTransacao() {
	    try {
	        if (em.getTransaction().isActive()) {
	            em.getTransaction().commit();
	        }
	    } catch (Exception e) {
	        em.getTransaction().rollback();
	        throw new RuntimeException("Erro ao comitar transação");
	    }
	    return this;
	}
	
	// Método incluir registro
	public DAO<E> incluirE(E entidade) {
		em.persist(entidade);
		return this;
	}
	
	// Open transaction, add data and Close transaction
	public DAO<E> incluirTransacionalo(E entidade) {
		return this.abrirTransacao().incluirE(entidade).comitarTransacao();
	}
	
	// Método para obter os registros da tabela
	public List<E> obterTodos(int quantidade, int deslocamento) {
		if (classe == null) {
			throw new UnsupportedOperationException("Classe nula");
		}
		String jpql = "select e from " + classe.getName() + " e";
		TypedQuery<E> query = em.createQuery(jpql, classe);
		query.setMaxResults(quantidade);
		query.setFirstResult(deslocamento);
		return query.getResultList();
	}
	
	// Método para resgatar um dado pelo id
	public E getDataById(Object id) {
		if (classe == null) {
			throw new UnsupportedOperationException("Classe nula");
		}
		return em.find(classe, id);
	}
	
	// Deletar pelo id
	public DAO<E> deleteById(Long id) {
		if (classe == null) {
			throw new UnsupportedOperationException("Classe nula");
		}
		
		abrirTransacao(); // Begin transaction
		E entidadeId = em.find(classe, id);
		if (entidadeId != null) {
			em.remove(entidadeId);
		}
		comitarTransacao(); // Commit transaction
		return this;
	}
	
	// Update
	public DAO<E> updateData(E entidade) {
		abrirTransacao(); // Begin transaction
	    em.merge(entidade); // Update data
	    comitarTransacao(); // Commit transaction
	    return this;
	}
	
	public void closeEM() {
	    if (em.isOpen()) {
	        em.close();
	    }
	}

}
