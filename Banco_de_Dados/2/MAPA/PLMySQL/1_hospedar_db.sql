/*
**************************************
-- 1. Crie o esquema de banco de dados 
**************************************
*/
CREATE SCHEMA hospedar_db;

USE hospedar_db;

/*
**************************************
-- 2. Crie as tabelas: 
**************************************
--> "Hotel"
--> "Quarto"
--> "Cliente"
--> "Hospedagem"
**************************************
*/
CREATE TABLE Hotel (
	hotel_id  INT AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    cidade VARCHAR(100) NOT NULL,
    uf VARCHAR(2) NOT NULL,
    classificacao INT NOT NULL COMMENT 'Classificação do hotel em estrelas (1 até 5).',
    
    CONSTRAINT hotel_id_pk PRIMARY KEY(hotel_id )
);

CREATE TABLE Quarto (
	quarto_id INT AUTO_INCREMENT,
    hotel_id INT NOT NULL,
    numero INT NOT NULL COMMENT 'Número do quarto.',
    tipo VARCHAR(50) NOT NULL COMMENT 'Tipo de quarto: Standard, Deluxe, Suíte',
    preco_diaria  DECIMAL(10, 2) NOT NULL,
    
    CONSTRAINT quarto_id_pk PRIMARY KEY(quarto_id),
    CONSTRAINT hotel_id_fk FOREIGN KEY(hotel_id) REFERENCES Hotel(hotel_id),
    CONSTRAINT tipo_ck CHECK(tipo IN('Standard', 'Deluxe', 'Suíte')),
    CONSTRAINT preco_diaria_ck CHECK(preco_diaria > 0)
);

CREATE TABLE Cliente (
	cliente_id INT AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    telefone VARCHAR(20) NOT NULL,
    cpf VARCHAR(11) NOT NULL,
    
    CONSTRAINT cliente_id_pk PRIMARY KEY(cliente_id),
    CONSTRAINT cpf_un UNIQUE(cpf),
    CONSTRAINT cpf_ck CHECK(CHAR_LENGTH(cpf) = 11)
);

CREATE TABLE Hospedagem (
	hospedagem_id INT AUTO_INCREMENT,
    cliente_id INT NOT NULL,
    quarto_id INT NOT NULL,
    dt_checkin DATE NOT NULL,
    dt_checkout DATE NOT NULL,
    Valor_total_hosp FLOAT NOT NULL,
    status_hosp VARCHAR(10) NOT NULL,
    
    CONSTRAINT hospedagem_id_pk PRIMARY KEY(hospedagem_id ),
    CONSTRAINT cliente_id_fk FOREIGN KEY(cliente_id) REFERENCES Cliente(cliente_id)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
    CONSTRAINT quarto_id_fk FOREIGN KEY(quarto_id) REFERENCES Quarto(quarto_id),
    CONSTRAINT Valor_total_hosp_ck CHECK(Valor_total_hosp > 0),
    CONSTRAINT status_hosp_ck CHECK(status_hosp IN('reserva', 'finalizada', 'hospedado', 'cancelada'))
);

-- Adiciona Comentário ao atributo 'status_hosp' da tabela 'Hospedagem'
ALTER TABLE Hospedagem
	MODIFY COLUMN status_hosp VARCHAR(50) NOT NULL
		COMMENT 'reserva = Reservado pelo Cliente;
				finalizada = Hospedagem Concluida;
				hospedado = o Cliente está Hospedado;
				cancelada = A Reserva foi Cancelada.';

/*
***************************************
3. Insira dados artificiais nas tabelas
--> "Hotel" (2 hotéis)
--> "Quarto"(5 para cada hotel)
--> "Cliente"(3 clientes)
--> "Hospedagem" (20 hospedagens, 5 para cada um dos “Status_hosp”) 
**************************************
*/

INSERT INTO Hotel (nome, cidade, uf, classificacao)
VALUES 
	('Hotel Beira Mar', 'Natal', 'RN', 5),
    ('Hotel Mirante do Lago', 'Natal', 'RN', 4);

INSERT INTO Quarto (hotel_id, numero, tipo, preco_diaria)
VALUES 
	(1, 100, 'Standard', 178.50),
	(1, 101, 'Deluxe', 278.00),
    (1, 102, 'Standard', 178.50),
    (1, 103, 'Suíte', 290.50),
    (1, 104, 'Suíte', 290.50),
    (2, 10, 'Standard', 290.50),
    (2, 12, 'Standard', 290.50),
    (2, 14, 'Standard', 290.50),
    (2, 16, 'Standard', 290.50),
    (2, 18, 'Standard', 290.50);

INSERT INTO Cliente (nome, email, telefone, cpf)
VALUES 
	('Antonio Zimermax', 'antzim23@hostname.com', '31 98487-3251', '32174147098'),
    ('Ana Maria Oliveria', 'olivasana@hostname.com', '11 99885-7925', '21741470981'),
    ('Jonas Baleeiro', 'jonasbal@hostname.com', '31 98875-2122', '67784220111');

INSERT INTO Hospedagem (cliente_id, quarto_id, dt_checkin, dt_checkout, Valor_total_hosp, status_hosp)
VALUES 
	(1, 1, '2023-11-20', '2023-11-25', 892.50, 'finalizada'),
    (1, 2, '2023-12-01', '2023-12-02', 278.00, 'finalizada'),
    (1, 1, '2024-01-20', '2024-01-22', 357.00, 'finalizada'),
    (2, 1, '2023-11-25', '2023-11-26', 178.50, 'finalizada'),
    (2, 6, '2023-12-20', '2023-12-22', 581.00, 'finalizada'),
    (2, 1, '2023-12-22', '2023-12-23', 178.50, 'cancelada'),
    (2, 3, '2024-01-05', '2024-01-07', 357.00, 'cancelada'),
    (1, 1, '2024-01-05', '2024-01-07', 357.00, 'cancelada'),
    (3, 7, '2024-01-05', '2024-01-07', 581.00, 'cancelada'),
    (3, 8, '2024-02-20', '2024-02-21', 290.50, 'cancelada'),
    (2, 10, '2024-05-20', '2024-05-30', 2905.00, 'hospedado'),
    (1, 3, '2024-05-20', '2024-05-30', 892.50, 'hospedado'),
    (1, 4, '2024-05-20', '2024-05-30', 892.50, 'hospedado'),
    (3, 6, '2024-05-20', '2024-05-30', 892.50, 'hospedado'),
    (3, 7, '2024-05-20', '2024-05-30', 892.50, 'hospedado'),
    (1, 1, '2024-06-01', '2024-06-05', 892.50, 'reserva'),
    (3, 2, '2024-07-20', '2024-07-25', 556.00, 'reserva'),
    (3, 3, '2024-07-20', '2024-07-25', 892.50, 'reserva'),
    (2, 8, '2024-07-20', '2024-07-25', 1452.50, 'reserva'),
    (2, 7, '2024-07-20', '2024-07-25', 1452.5, 'reserva');
