/*
d. ​Apresentar o cliente com maior número de hospedagens
(não importando o tempo em que ficou hospedado);
*/
USE hospedar_db;

SELECT
	Cliente.nome AS Cliente,
    COUNT(*) AS Hospedagens
FROM Hospedagem
INNER JOIN Cliente ON Hospedagem.cliente_id = Cliente.cliente_id
WHERE Hospedagem.status_hosp = 'finalizada'
GROUP BY Cliente.nome
LIMIT 1;
