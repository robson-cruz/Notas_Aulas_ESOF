/*
i. ​Listar todos os quartos que ainda não receberam hóspedes.
*/
USE hospedar_db;

SELECT
	Quarto.numero AS Quarto,
    Hotel.nome AS Hotel
FROM Quarto
INNER JOIN Hotel ON Quarto.hotel_id = Hotel.hotel_id
WHERE quarto_id NOT IN (SELECT quarto_id FROM Hospedagem);
