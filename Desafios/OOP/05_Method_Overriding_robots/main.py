class Robot:
    """Definition of the base class Robot"""
    def __init__(self, name, variety):
        """The initializer method for the class Robot

        Arguments:
              name -- a string representing robot's name
              variety -- a string representing the function of the robot
        """
        self.name = name
        self.variety = variety
        print("Robot")

    def get_info(self):
        """get_info method to return information about a particular instance

        Returns:
            A formatted string providing information about the robot
        """
        return "{} is a {} robot".format(self.name, self.variety)


class ServiceRobot(Robot):
    """Definition of the subclass ServiceRobot"""
    def __init__(self, name):
        """The initializer method for the class ServiceRobot

        Arguments:
              name -- a string representing robot's name
        """
        super().__init__(name, "service")  # Call the parent class's __init__ with "service" as variety


# Example usage
chappi = ServiceRobot("Chappi")
print(chappi.get_info())
