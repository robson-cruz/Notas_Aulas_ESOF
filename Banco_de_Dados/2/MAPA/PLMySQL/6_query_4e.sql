/*
e. ​Apresentar clientes que tiveram hospedagem “cancelada”,
os respectivos quartos e hotéis.
*/
USE hospedar_db;

SELECT
	Cliente.nome AS Cliente,
	Quarto.numero AS 'Número Quarto',
	Hotel.nome AS Hotel
FROM Cliente
INNER JOIN Hospedagem ON Cliente.cliente_id = Hospedagem.cliente_id
INNER JOIN Quarto ON Hospedagem.quarto_id = Quarto.quarto_id
INNER JOIN Hotel ON Quarto.hotel_id = Hotel.hotel_id
WHERE status_hosp = 'cancelada';
