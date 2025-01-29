from flask_login import UserMixin
from config import db


class User(UserMixin, db.Model):
    """Representation of the User class
    UserMixin allows us to use methods such as is_authenticated(), is_active(), is_anonymous(), and get_id().
    """
    __tablename__ = "user"
    user_id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100), nullable=False)
    email = db.Column(db.String(64), unique=True, nullable=False)
    role = db.Column(db.String(50), nullable=False)
    password = db.Column(db.String(300), nullable=False)

    def get_id(self):
        return str(self.user_id)  # Ensure it returns a string


class Motorcycle(db.Model):
    __tablename__ = "motorcycle"
    motorcycle_id = db.Column(db.Integer, primary_key=True)
    marca = db.Column(db.String(50), nullable=False)
    modelo = db.Column(db.String(50), nullable=False)
    combustivel = db.Column(db.String(50), nullable=False)
    cor = db.Column(db.String(50), nullable=False)
    ano = db.Column(db.Integer, nullable=False)
    side_car = db.Column(db.String(4), nullable=True)


class Car(db.Model):
    __tablename__ = "car"
    car_id = db.Column(db.Integer, primary_key=True)
    marca = db.Column(db.String(50), nullable=False)
    modelo = db.Column(db.String(50), nullable=False)
    combustivel = db.Column(db.String(50), nullable=False)
    cor = db.Column(db.String(50), nullable=False)
    portas = db.Column(db.Integer, nullable=False)
    ano = db.Column(db.Integer, nullable=False)
