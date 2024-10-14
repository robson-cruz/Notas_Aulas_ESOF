import java.util.HashMap;

public class Main {
  public static void main(String[] args) {
    HashMap<String, Double> exameScores = new HashMap<String, Double>();

    exameScores.put("Programação de Sistemas I", 10.0);
    exameScores.put("Programação de Sistemas II", 9.5);
    exameScores.put("Administração de Conflito", 8.0);

    System.out.println("Programação de Sistemas II: " + exameScores.get("Programação de Sistemas II") + "\n");
    System.out.println(exameScores.toString() + "\n");

    exameScores.forEach((key, value) -> {
      if (value == 10) {
        System.out.printf("%s: %.0f\n", key, value);
      } else {
        System.out.printf("%s: %.1f\n", key, value);
      }
    });
  }
}
