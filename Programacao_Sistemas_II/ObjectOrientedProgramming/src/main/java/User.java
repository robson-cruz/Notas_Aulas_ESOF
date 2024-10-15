import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;


public class User {
  	private String name;
	private LocalDate birthDay;

	private ArrayList<Book> books = new ArrayList<Book>();
	
	// User constructor
	User(String name, String birthDay) {
		this.name = name;
		this.birthDay = LocalDate.parse(birthDay);
	};

	public String getName() {
		return this.name;
	}
	public String getBirthDay() {
		return this.birthDay.toString();
	}
	
	public int age() {
		Period age = Period.between(this.birthDay, LocalDate.now());

		return age.getYears();
	}

	public String borrowedBooks() {
		String books = "";
		for (Book book : this.books) {
			books += book.toString() + "\n";
		}
		return books;
	}
	
	public void borrow(Book book) {
		this.books.add(book);
	}

}