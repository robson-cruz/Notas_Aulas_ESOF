package file_handling;

public class Main {

	public static void main(String[] args) {
		String filePath = "data/customers.txt";
       
		String data = TextFile.readerFile(filePath);
		TextFile.head(data, 5);
	}

}
