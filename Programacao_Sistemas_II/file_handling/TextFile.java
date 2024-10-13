package file_handling;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TextFile {
	public static String readerFile(String path) {
        StringBuilder fileContent = new StringBuilder(); // Use StringBuilder to accumulate the file content

        try {
            File myFile = new File(path);
            Scanner txtReader = new Scanner(myFile);

            while (txtReader.hasNextLine()) {
                // Append each line with a newline
                fileContent.append(txtReader.nextLine()).append("\n");
            }
            txtReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Erro ao ler arquivo!");
            e.printStackTrace();

        }
        return fileContent.toString();
    }
	
	// Show a maximum of 10 lines of the file
	public static void head(String data, int n) {
		// StringBuilder to list
		String[] linesArray = data.split("\n");
		ArrayList<String> linesData = new ArrayList<String>(Arrays.asList(linesArray));
		
		System.out.println("Contéudo das " + n + " Primeiras linhas:\n");
		for (int i = 0; i < Math.min(n, linesData.size()); i++) {
			System.out.println(linesData.get(i));
		}
	}
}
