
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String dnaSequence = scanner.nextLine().trim().toUpperCase();

      int a = 0, c = 0, g = 0, t = 0;

      for (int i = 0; i < dnaSequence.length(); i++) {
        char nucleotide = dnaSequence.charAt(i);
          switch (nucleotide) {
              case 'A' -> a++;
              case 'C' -> c++;
              case 'G' -> g++;
              case 'T' -> t++;
              default -> {
              }
          }
      }

      int total = dnaSequence.length();

      System.out.printf("A: %.2f%%\nC: %.2f%%\nG: %.2f%%\nT: %.2f%%\n",
              (double)a/total*100, (double)c/total*100, (double)g/total*100, (double)t/total*100);
    }
  }
}
