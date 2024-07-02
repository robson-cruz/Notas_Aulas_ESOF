USE AlugaFacil;
GO

CREATE LOGIN crazy   
    WITH PASSWORD = '8fdKJl3$nlNv3049jsKK';  

CREATE USER crazy_usr FOR LOGIN crazy   
    WITH DEFAULT_SCHEMA = Carro;  
GO

GRANT CREATE TABLE TO crazy_usr;
GO
