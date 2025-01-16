public class Main {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[4];

        Square square = new Square();
        square.setSide(5); // Side = 5, Area = 25

        Rectangle rectangle = new Rectangle();
        rectangle.setWidth(4);
        rectangle.setHeight(6); // Width = 4, Height = 6, Area = 24

        Shape genericShape1 = new Shape(); // Generic shape, Area = 0
        Shape genericShape2 = new Shape(); // Another generic shape, Area = 0

        shapes[0] = square;
        shapes[1] = rectangle;
        shapes[2] = genericShape1;
        shapes[3] = genericShape2;

        int totalArea = Sum.sumOfAreas(shapes);
        System.out.println("Total Area: " + totalArea); // Output: Total Area: 49
    }
}
