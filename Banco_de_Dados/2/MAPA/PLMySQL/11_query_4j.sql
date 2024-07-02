/*
j. ​Apresentar a média de preços de diárias em todos os hotéis, por tipos de quarto.
*/
USE hospedar_db;

SELECT
	nome AS Hotel,
    tipo AS 'Tipo Quarto',
    ROUND(AVG(preco_diaria), 2) AS 'Valor Médio Diária'
FROM Hotel
INNER JOIN Quarto ON Hotel.hotel_id = Quarto.hotel_id
GROUP BY nome, tipo;
