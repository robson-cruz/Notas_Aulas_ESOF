class Triangle:
    def __init__(self, side1, side2, side3):
        """The initializer method for the class Triangle

        Arguments:
            side1 -- the length of the first side from a triangle
            side2 -- the length of the second side from a triangle
            side3 -- the length of the third side from a triangle
        """
        self.side1 = side1
        self.side2 = side2
        self.side3 = side3

    def get_perimeter(self):
        """Return the perimeter of a given triangle"""
        return self.side1 + self.side2 + self.side3


class EquilateralTriangle(Triangle):
    def __init__(self, side):
        """The initializer method for the class EquilateralTriangle

        Arguments:
            side -- the length of each side of the equilateral triangle
        """
        super().__init__(side, side, side)
