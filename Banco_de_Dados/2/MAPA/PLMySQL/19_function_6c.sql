/**
6. Efetue a criação das seguintes funções utilizando PL/MySQL:
c. Criar uma function chamada "VerificarDisponibilidadeQuarto" que aceita quarto_id e data como parâmetros.
A função deve retornar um valor booleano indicando se o quarto está disponível ou não para reserva na data especificada.​
*/
USE hospedar_db;

DELIMITER $$
CREATE FUNCTION VerificarDisponibilidadeQuarto(id INT, data_busca DATE)
RETURNS BOOLEAN DETERMINISTIC

COMMENT 'A VerificarDisponibilidadeQuarto deve receber a data no formato YYYY-MM-DD'

BEGIN
	DECLARE busca BOOLEAN;
	DECLARE ocupado INT;
    
    SELECT COUNT(*) INTO ocupado
	FROM hospedar_db.Hospedagem
    INNER JOIN hospedar_db.Quarto ON hospedar_db.Hospedagem.quarto_id = hospedar_db.Quarto.quarto_id
	WHERE Quarto.quarto_id = id 
		AND status_hosp NOT IN ( 'finalizada', 'cancelada')
				AND data_busca NOT BETWEEN dt_checkin AND dt_checkout;

    IF ocupado = 0 THEN
		SET busca = TRUE;
	ELSE 
		SET busca = FALSE;
	END IF;
    
    RETURN busca;

END $$
DELIMITER ;
