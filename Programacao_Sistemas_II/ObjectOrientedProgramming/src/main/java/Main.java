/**
* Java Programming for Beginners
* Credits: FreeCodeCamp.org
* https://youtu.be/A74TOX803D0?si=DsthjGEY3HFBw_is
*/

public class Main {
  public static void main(String[] args) {
    User user = new User("Jane", "1995-01-31");

    Book carmillaBook = new Book("Carmilla", "Sheridan Le Fanu", 450);
    AudioBook draculaAudioBook = new AudioBook("Dracula", "Bram Stoker", 30000);
    Ebook jeeves = new Ebook("Carry on Jeeves", "P.G. Wodehouse", 280, "PDF");
    
    user.borrow(carmillaBook);
  
    System.out.printf("%s was born back in %s and her is now %s years old.\n\n", user.getName(),
                      user.getBirthDay().toString(), user.age());
    
    System.out.printf("%s has borrowed these books: %s\n", user.getName(), user.borrowedBooks());

    System.out.println(carmillaBook.toString());
    // the 'AudioBook' class has inherited the 'toString' method from 'Book' class
    System.out.println(draculaAudioBook.toString());

    System.out.println(jeeves.toString());
  }
}
