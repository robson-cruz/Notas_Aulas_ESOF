public class Robot {
    String name;
    String model;
    int lifeTime;

    // no-argument constructor
    public Robot() {
        this.name = "Anonymous";
        this.model = "Unknown";
        System.out.println("First Constructor with no-argument.");
    }
    // two arguments constructor that invokes the third one
    public Robot(String name, String model) {
        this(name, model, 15);
    }
    // three-argument constructor that fills all fields.
    public Robot(String name, String model, int lifeTime) {
        this.name = name;
        this.model = model;
        this.lifeTime = lifeTime;
        System.out.println("Second Constructor with 3 arguments.");
    }
}
