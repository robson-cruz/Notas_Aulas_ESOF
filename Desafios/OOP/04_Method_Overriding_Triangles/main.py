from geometry import triangle_utils

triangle = triangle_utils.Triangle(12, 8, 4)
print(triangle.get_perimeter())

eq_triangle = triangle_utils.EquilateralTriangle(4)
print(eq_triangle.get_perimeter())
