class Sum {
    public static int sumOfAreas(Shape[] array) {
        int totalArea = 0;

        for (Shape shape : array) {
            if (shape instanceof Rectangle rectangle) {
                totalArea += rectangle.getWidth() * rectangle.getHeight();  // Area of a rectangle
            } else if (shape instanceof Square square) {
                totalArea += square.getSide() * square.getSide();  // Area of a square
            }
            // If the shape is a base Shape, area is 0 (no need for additional handling)
        }

        return totalArea;
    }
}
