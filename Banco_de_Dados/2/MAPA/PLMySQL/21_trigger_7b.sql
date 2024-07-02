/*
7. Efetue a criação das seguintes triggers utilizando PL/MySQL:

b.Cria um trigger chamado "AposDeletarCliente" que é acionado após a exclusão de um cliente na tabela "Cliente".
O trigger deve registrar a exclusão em uma tabela de log.​
*/
USE hospedar_db;

DELIMITER $$
CREATE TRIGGER AposDeletarCliente
AFTER DELETE ON Cliente
FOR EACH ROW
BEGIN
	INSERT INTO LogExclusaoCliente (cliente_id, nome, cpf, data_hora)
    VALUES (OLD.cliente_id, OLD.nome, OLD.cpf, NOW(), SYSTEM_USER());
END $$
DELIMITER ;
