/**
7. Efetue a criação das seguintes triggers utilizando PL/MySQL:

a. Criar um trigger chamado "AntesDeInserirHospedagem" que é acionado antes de uma inserção na tabela "Hospedagem".

O trigger deve verificar se o quarto está disponível na data de check-in.
Se não estiver, a inserção deve ser cancelada.
*/
USE hospedar_db;

DELIMITER $$
CREATE TRIGGER AntesDeInserirHospedagem
BEFORE INSERT ON Hospedagem
FOR EACH ROW
BEGIN
	IF NOT VerificarDisponibilidadeQuarto(NEW.quarto_id, NEW.dt_checkin) THEN
		SIGNAL SQLSTATE '45000'
			SET MESSAGE_TEXT = 'O quarto não está disponível na data de check-in.';
	END IF;
END $$
DELIMITER ;
