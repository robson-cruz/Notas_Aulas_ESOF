import publication.SubmitPublication;

import java.util.Scanner;

/**
 * Entry point for testing the Publication hierarchy.
 */
public class Main {
    /**
     * Reads input data from the user and submits it for processing.
     *
     * @param args command-line arguments (not used)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String data = scanner.nextLine();
        SubmitPublication.submitData(data);
    }
}