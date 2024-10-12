package aula_01;

/** 
 * https://www.youtube.com/live/LdrvgAZZy8w
 */
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Hello Client!!");
		
		Cliente cliente1 = new Cliente(1, "Robson Cruz", "rcsdev@gmailcom", "98 984531145");
		
		String output_txt = "Cliente 1: " + cliente1.getNome();
		
		System.out.println(output_txt);
	}

}
