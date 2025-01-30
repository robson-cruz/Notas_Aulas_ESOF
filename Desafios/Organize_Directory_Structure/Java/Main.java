import java.io.File;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        // List all file in the input directory
        File directory = new File("dir_to_organize");
        File[] filePaths = directory.listFiles(File::isFile);
        if (filePaths == null) {
            System.out.println("Diretório inválido ou vazio.");
            return;
        }

       // Get each file extension and create a directory for each file extension and move files
        HashMap<String, Integer> fileMoved = new HashMap<>();
        for (File path : filePaths) {
            String fileName = path.getName();
            int dotIndex = fileName.lastIndexOf(".");

            // Check if the file has a valid extension
            if (dotIndex > 0 && dotIndex < fileName.length() - 1) { // Skip hidden files
                String ext = fileName.substring(dotIndex + 1); // get the file extension
                fileMoved.put(ext, fileMoved.getOrDefault(ext, 0) + 1);

                // Create a directory for each extension, if exist
                String filePathString = directory + File.separator + ext;
                File filePath = new File(filePathString);
                if (!filePath.exists()) {
                    filePath.mkdir();
                }

                // Move the file to the corresponding directory
                File newFileLocation = new File(filePathString + File.separator + fileName);
                boolean success = path.renameTo(newFileLocation);

                if (!success) {
                    System.out.println("Falha ao mover: " + fileName);
                }
            }
        }

        // Print the result
        System.out.printf("%-10s | %-10s", "Extensão", "Arquivos Movidos");  // Header
        System.out.println("\n------------------------------");

        fileMoved.forEach((key, value) -> System.out.printf("%-10s | %-10s", key, value));

    }
}
