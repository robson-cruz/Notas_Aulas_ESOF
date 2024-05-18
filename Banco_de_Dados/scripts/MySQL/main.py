from sqlalchemy import create_engine, text
import os


# Connection information
username = os.environ['USERNAME']
password = os.environ['PASSWD']
host = 'courses.csrrinzqubik.us-east-1.rds.amazonaws.com'
port = '3306'  # Porta padrão para MySQL
database = 'tweater'

# Connection URL for MySQL
DATABASE_URL = f'mysql+pymysql://{username}:{password}@{host}:{port}/{database}'

# Create the connection engine
engine = create_engine(DATABASE_URL)

# Test the connection
try:
    with engine.connect() as connection:
        result = connection.execute(text("SELECT * FROM tweats;"))
        print(result.fetchone())
except Exception as e:
    print(f"Erro ao conectar: {e}")
