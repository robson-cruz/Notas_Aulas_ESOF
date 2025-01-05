package file_handling;

public class Main {

	public static void main(String[] args) {
		//String filePath = "pets.csv";
		String filePath = "pets.csv";
       
		//String data = TextFile.readerFile(filePath);
		//TextFile.head(data, 5);
		String data = CsvFile.readerFile(filePath);
		CsvFile.head(data, 5);
	}

}
