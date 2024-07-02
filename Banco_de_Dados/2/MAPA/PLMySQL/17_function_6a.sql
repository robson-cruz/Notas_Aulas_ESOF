/**
6. Efetue a criação das seguintes funções utilizando PL/MySQL:
a. Criar uma function chamada "TotalHospedagensHotel" que aceita hotel_id como parâmetro.
A função deve retornar o número total de hospedagens realizadas em um determinado hotel.​
*/
USE hospedar_db;

DELIMITER $$
CREATE FUNCTION TotalHospedagensHotel(id INT)
RETURNS INT DETERMINISTIC

BEGIN
	DECLARE num_hospedagem INT;
	SELECT COUNT(*) INTO num_hospedagem
	FROM hospedar_db.Hospedagem
    INNER JOIN hospedar_db.Quarto ON hospedar_db.Hospedagem.quarto_id = hospedar_db.Quarto.quarto_id
	WHERE hotel_id = id AND status_hosp = 'finalizada';

	RETURN num_hospedagem;
END $$

DELIMITER ;
