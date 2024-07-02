/**
6. Efetue a criação das seguintes funções utilizando PL/MySQL:
b. Criar uma function chamada "ValorMedioDiariasHotel" que aceita hotel_id como parâmetro.
A função deve calcular e retornar o valor médio das diárias dos quartos deste hotel.
*/
USE hospedar_db;

DELIMITER $$
CREATE FUNCTION ValorMedioDiariasHotel(id INT)
RETURNS DECIMAL(10, 2) DETERMINISTIC

BEGIN
	DECLARE valor_medio_diaria DECIMAL(10, 2);
    
    SELECT AVG(Quarto.preco_diaria) INTO valor_medio_diaria
	FROM hospedar_db.Hospedagem
    INNER JOIN hospedar_db.Quarto ON hospedar_db.Hospedagem.quarto_id = hospedar_db.Quarto.quarto_id
	WHERE hotel_id = id;
    
	RETURN valor_medio_diaria;
END $$
DELIMITER ;