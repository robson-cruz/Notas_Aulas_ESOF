import java.time.LocalDate;
import java.time.YearMonth;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        try (Scanner scanner = new Scanner(System.in)) {
            // Read year and month as input
            if (!scanner.hasNextInt()) {
                throw new java.time.DateTimeException("Invalid input. Please enter a numeric year.");
            }
            int year = scanner.nextInt();

            if (!scanner.hasNextInt()) {
                throw new java.time.DateTimeException("Invalid input. Please enter a numeric month.");
            }
            int month = scanner.nextInt();

            // Validate the month
            if (month < 1 || month > 12) {
                throw new java.time.DateTimeException("Invalid month. Please enter a value between 1 and 12.");
            }

            // Get the first day of the month
            YearMonth yearMonth = YearMonth.of(year, month);
            LocalDate firstDay = yearMonth.atDay(1);

            // Loop through th days of month to find all Mondays
            for (LocalDate date = firstDay; date.getMonthValue() == month; date = date.plusDays(1)) {
                if (date.getDayOfWeek().getValue() == 1) {  // 1 correspond to Monday
                    System.out.println(date);
                }
            }
        } catch (java.time.DateTimeException e) {
            // Handle invalid year/month combinations
            System.out.println("Error: " + e.getMessage());
        }
    }
}