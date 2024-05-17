CREATE SCHEMA mae_bebe;

USE mae_bebe;

CREATE TABLE estado (
	id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    uf VARCHAR(2)
);

CREATE TABLE cidade (
	id INT PRIMARY KEY AUTO_INCREMENT,
    id_estado INT,
    nome VARCHAR(100) NOT NULL,
    
    CONSTRAINT FOREIGN KEY (id_estado) REFERENCES estado(id)
);

CREATE TABLE endereco (
	 id INT PRIMARY KEY AUTO_INCREMENT,
     id_cidade INT,
     logradouro VARCHAR(100),
     numero INT,
     bairro VARCHAR(50),
     cep VARCHAR(8) NOT NULL,
     completo VARCHAR(100),
     ponto_referencia VARCHAR(100),
     
     CONSTRAINT FOREIGN KEY (id_cidade) REFERENCES cidade(id)
);

CREATE TABLE mae (
	id INT PRIMARY KEY AUTO_INCREMENT,
    id_endereco INT,
    nome VARCHAR(150) NOT NULL,
    data_nascimento DATE,
    
    CONSTRAINT FOREIGN KEY (id_endereco) REFERENCES endereco(id)
);

CREATE TABLE telefone_mae (
	id INT PRIMARY KEY AUTO_INCREMENT,
    id_mae INT,
    numero VARCHAR(15) NOT NULL,
    tipo TINYINT,
    
    CONSTRAINT FOREIGN KEY (id_mae) REFERENCES mae(id)
);

CREATE TABLE especialidade (
	id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL
);

CREATE TABLE medico (
	crm INT PRIMARY KEY,
    id_especialidade INT,
	nome VARCHAR(150) NOT NULL,
    celular VARCHAR(15),
    
    CONSTRAINT FOREIGN KEY (id_especialidade) REFERENCES especialidade(id)
);

CREATE TABLE bebe (
	id INT PRIMARY KEY AUTO_INCREMENT,
    crm_medico INT NOT NULL,
    id_mae INT,
    nome VARCHAR(150) NOT NULL,
    data_nascimento DATE NOT NULL,
    peso DECIMAL(5, 2),
    altura TINYINT,
    CONSTRAINT FOREIGN KEY (crm_medico) REFERENCES medico(crm),
    CONSTRAINT FOREIGN KEY (id_mae) REFERENCES mae(id)
);
