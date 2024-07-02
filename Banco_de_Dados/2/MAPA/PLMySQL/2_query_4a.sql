/*
4. Escreva as seguintes consultas e comandos SQL:
a. Listar todos os hotéis e seus respectivos quartos, apresentando os seguintes campos:
-- Para hotel, nome e cidade;
-- Para quarto, tipo e preco_diaria;
*/
USE Hospedar_db;

SELECT DISTINCT
	nome AS Nome,
    cidade AS Cidade,
    tipo AS Tipo,
    preco_diaria AS 'Preço Diária'
FROM Hotel
INNER JOIN Quarto ON Hotel.hotel_id = Quarto.hotel_id;
