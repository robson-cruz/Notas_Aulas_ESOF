/*
g. ​Listar todos os clientes que já fizeram uma reserva em um hotel específico;
*/
USE hospedar_db;

SELECT
	Cliente.nome AS Cliente,
    Hotel.nome AS Hotel,
    status_hosp AS 'Status Hospedagem'
FROM Cliente
INNER JOIN Hospedagem ON Cliente.cliente_id = Hospedagem.cliente_id
INNER JOIN Quarto ON Hospedagem.quarto_id = Quarto.quarto_id
INNER JOIN Hotel ON Quarto.hotel_id = Hotel.hotel_id
WHERE Hotel.nome = 'Hotel Mirante do Lago';
