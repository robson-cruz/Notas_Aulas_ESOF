package file_handling;

public class Main {

	public static void main(String[] args) {
		String filePath = "data/customers.txt";
       
        //System.out.println(TextFile.readerFile(filePath));
		String data = TextFile.readerFile(filePath);
		TextFile.head(data, 5);
	}

}
