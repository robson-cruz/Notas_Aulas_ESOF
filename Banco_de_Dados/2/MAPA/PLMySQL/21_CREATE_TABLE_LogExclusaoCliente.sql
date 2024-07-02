USE hospedar_db;

CREATE TABLE LogExclusaoCliente (
    log_id INT AUTO_INCREMENT,
    cliente_id INT,
    nome VARCHAR(100),
    cpf VARCHAR(11),
    data_hora DATETIME,
	usuario VARCHAR(100),
    
    CONSTRAINT log_id_pk PRIMARY KEY(log_id)
);
