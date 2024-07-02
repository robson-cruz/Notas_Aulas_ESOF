/*
f. ​Calcular a receita de todos os hotéis
(hospedagem com status_hosp igual a “finalizada”),
 ordenado de forma decrescente;
*/
USE hospedar_db;

SELECT
	nome AS Hotel,
    SUM(Valor_total_hosp) AS Receita
FROM Hotel
INNER JOIN Quarto ON Hotel.hotel_id = Quarto.hotel_id
INNER JOIN Hospedagem ON Quarto.quarto_id = Hospedagem.quarto_id
WHERE status_hosp = 'finalizada'
GROUP BY nome;
