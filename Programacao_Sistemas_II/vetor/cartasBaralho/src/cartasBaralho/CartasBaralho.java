/**
 * 
 */
package cartasBaralho;

/**
 * Baralho francês com 52 cartas usando vetor
 */
public class CartasBaralho {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String[] naipes = {"Copas", "Ouros", "Espadas", "Paus"};
		String[] valores = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
		String[] baralho = new String[52];
		
		int index = 0;
		for (String naipe : naipes) {
			for (String valor : valores) {
				baralho[index++] = valor + " de " + naipe;
			}
		}
		
		for (String carta : baralho) {
			System.out.printf("\t%s \n", carta);
			if (carta.contains("K")) {
				System.out.println("");
				System.out.println("");
			}
		}

	}

}
