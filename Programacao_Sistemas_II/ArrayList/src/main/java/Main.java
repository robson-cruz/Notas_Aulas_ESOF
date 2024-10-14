import java.util.ArrayList;
import java.util.Comparator;

public class Main {
  public static void main(String[] args) {
    ArrayList<Integer> numbers = new ArrayList<Integer>();

    for (int i = 11; i > 0; i--) {
      numbers.add(i + 1);
    }

    System.out.println(numbers.toString() + "\n");
    
    // Which element is in the index 0?
    System.out.println("The element 0 is: " + numbers.get(0) + "\n");
    
    // Remove an element from the array list using its index
    numbers.remove(0);
    System.out.println(numbers.toString() + "\n");
    
    // Remove the element 10 from the array list
    numbers.remove(Integer.valueOf(10));
    System.out.println(numbers.toString() + "\n");
    
    // Sorting the array list in ascending order
    numbers.sort(Comparator.naturalOrder());
    System.out.println(numbers.toString() + "\n");
    
    // Sorting the array list in descending order
    numbers.sort(Comparator.reverseOrder());
    System.out.println(numbers.toString() + "\n");
    
    // get the max value from the array list
    int maxValue = numbers.get(0);
    
    for (int i = 0; i < numbers.size(); i++) {
      if (numbers.get(i) > maxValue) {
        maxValue = numbers.get(i);
      }
    }

    System.out.println("The maximum value is: " + maxValue + "\n");

    // Using the Stream API to get the max value from the array list
    int maximunValue = numbers.stream().
      max(Comparator.naturalOrder()).
      orElse(Integer.MIN_VALUE);
    
    System.out.println("The maximum value is: " + maximunValue + "\n");
  }
}