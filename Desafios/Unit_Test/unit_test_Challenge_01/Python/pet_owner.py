class PetOwner:
    def __init__(self, owner, spec, pet_name):
        self.owner = owner
        self.spec = spec
        self.pet_name = pet_name

    def owner_with_pet(self):
        return f"{self.owner} has a {self.spec} named {self.pet_name}"
