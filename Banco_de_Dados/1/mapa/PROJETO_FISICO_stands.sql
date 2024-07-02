-- Geração de Modelo físico
-- Sql ANSI 2003 - brModelo.



CREATE TABLE projeto (
id INT PRIMARY KEY,
descricao VARCHAR(500),
url_projeto VARCHAR(2083),
url_orcamento VARCHAR(2083),
id_equipe INT,
id_cliente INT,
id_status INT
);

CREATE TABLE colaborador (
id INT PRIMARY KEY,
cpf VARCHAR(11),
nome VARCHAR(150),
telefone VARCHAR(20),
email VARCHAR(100),
cargo INT,
salario FLOAT(8, 2),
endereco VARCHAR(250),
id_equipe INT,
id_cargo INT,
id_banco INT,
cod_banco VARCHAR(10),
banco VARCHAR(50),
agencia VARCHAR(10),
conta VARCHAR(10)/*falha: chave estrangeira*/
);

CREATE TABLE cargo (
id INT PRIMARY KEY,
titulo VARCHAR(50)
);

CREATE TABLE status (
id INT PRIMARY KEY,
nome VARCHAR(50),
data DATE
);

CREATE TABLE cliente (
id INT PRIMARY KEY,
nome VARCHAR(150),
cpf VARCHAR(11),
cnpj VARCHAR(14),
insc_estadual VARCHAR(9),
endereco VARCHAR(150),
telefone VARCHAR(100),
email VARCHAR(100)
);

CREATE TABLE equipe (
id INT PRIMARY KEY,
setor VARCHAR(50)
);

ALTER TABLE projeto ADD FOREIGN KEY(id_equipe) REFERENCES equipe (id);
ALTER TABLE projeto ADD FOREIGN KEY(id_cliente) REFERENCES cliente (id);
ALTER TABLE projeto ADD FOREIGN KEY(id_status) REFERENCES status (id);
ALTER TABLE colaborador ADD FOREIGN KEY(id_equipe) REFERENCES equipe (id);
ALTER TABLE colaborador ADD FOREIGN KEY(id_cargo) REFERENCES cargo (id);
