import os
from flask import Flask
from flask_bootstrap import Bootstrap5
from dotenv import load_dotenv
from flask_login import LoginManager
from flask_wtf import CSRFProtect
import logging
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
Bootstrap5(app)  # Add Bootstrap resources to the app
load_dotenv()  # Load environment variables from .env

# Flask configuration using environment variables
app.config['SECRET_KEY'] = os.getenv("APP_SECRET")
app.config['BOOTSTRAP_BOOTSWATCH_THEME'] = 'lumen'  # Apply the "lumen" Bootstrap theme to the app
csrf = CSRFProtect(app)

# Configure Flask-Login
login_manager = LoginManager()
login_manager.init_app(app)
login_manager.login_view = "login"
login_manager.login_message = "Por favor, faça login para acessar esta página."
login_manager.login_message_category = "info"
logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")

# Connect to the database
MySQL_PASSWORD = os.getenv("MySQL_PASSWORD")
app.config["SQLALCHEMY_DATABASE_URI"] = f"mysql+pymysql://root:{MySQL_PASSWORD}@127.0.0.1:3306/car_database"
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = True

db = SQLAlchemy()  # Import the db as an instance of SQLAlchemy

with app.app_context():
    db.init_app(app)
    db.create_all()
