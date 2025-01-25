from flask_wtf import FlaskForm
from wtforms.fields.choices import SelectField
from wtforms.fields.numeric import IntegerField
from wtforms.fields.simple import StringField, SubmitField, BooleanField, PasswordField, EmailField
from wtforms.validators import DataRequired, Length, Regexp, Email, InputRequired, NumberRange


class UserForm(FlaskForm):
    """UserForm class to representing a form to register new users i the database"""
    name = StringField("Nome", validators=[
        DataRequired(),
        Length(3, 100, message="Please provide a valid name"),
        Regexp(
            "^[a-zA-Z][a-zA-Z0-9_.]*$",
            0,
            "Nome de usuário deve conter somente letras, números, ponto ou underscore"
        )
    ])
    email = EmailField("Email", validators=[DataRequired(), Email(), Length(1, 64)])
    password = PasswordField("Senha", validators=[DataRequired(), Length(8, 300)])
    button = SubmitField("Cadastrar Usuário")


class LoginForm(FlaskForm):
    email = StringField("Email", validators=[InputRequired(), Email(), Length(1, 64)])
    password = PasswordField("Senha", validators=[InputRequired(), Length(min=8, max=72)])
    button = SubmitField("Entrar")


class MotorcycleForm(FlaskForm):
    marca = StringField("Marca", validators=[DataRequired()])
    modelo = StringField("Modelo", validators=[DataRequired()])
    combustivel = StringField("Combustivel", validators=[DataRequired()])
    cor = StringField("Cor", validators=[DataRequired()])
    ano = IntegerField("Ano", validators=[DataRequired(), NumberRange(4)])
    side_car = BooleanField("Side car")
    button = SubmitField("Cadastrar Moto")


class CarForm(FlaskForm):
    marca = StringField("Marca", validators=[DataRequired()])
    modelo = StringField("Modelo", validators=[DataRequired()])
    combustivel = SelectField(
        "Combustivel",
        validators=[DataRequired()],
        choices=["Gasolina", "Diesel", "Álcool", "Flex"]
    )
    cor = StringField("Cor", validators=[DataRequired()])
    ano = IntegerField("Ano", validators=[DataRequired(), NumberRange(4)])
    button = SubmitField("Cadastrar Carro")
