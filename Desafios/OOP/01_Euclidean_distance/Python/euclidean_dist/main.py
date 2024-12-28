import math


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dist(self, other):
        return math.sqrt((self.x - other.x)**2 + (self.y - other.y)**2)


# Example of use
p1 = Point(1.5, 1)
p2 = Point(1.5, 2)

print(p1.dist(p2))  # 1.0
