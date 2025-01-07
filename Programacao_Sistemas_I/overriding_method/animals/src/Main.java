import java.util.Scanner;

// Animal class
class Animal {
    public String makeSound() {
        // Method to return animal sound
        return "animal sound";
    }
}

// Dog class
class Dog extends Animal {
    // Override the makeSound method here
    @Override
    public String makeSound() {
        return "bark";
    }
}

// Cat class
class Cat extends Animal {
    @Override
    public String makeSound() {
        return "meow";
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String animalType = scanner.nextLine().strip().toLowerCase();

        // Depending on the input create instance of Animal or Dog and call it's makeSound method
        switch (animalType) {
            case "animal" -> {
                Animal animal = new Animal();
                System.out.println(animal.makeSound());
            }
            case "dog" -> {
                Dog dog = new Dog();
                System.out.println(dog.makeSound());
            }
            case "cat" -> {
                Cat cat = new Cat();
                System.out.println(cat.makeSound());
            }
        }
    }
}