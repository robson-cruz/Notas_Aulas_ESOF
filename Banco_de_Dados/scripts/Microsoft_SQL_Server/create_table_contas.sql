USE exercicios;
GO

CREATE TABLE contas (
    id INT IDENTITY PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    saldo DECIMAL(18, 2) NOT NULL
);
GO
