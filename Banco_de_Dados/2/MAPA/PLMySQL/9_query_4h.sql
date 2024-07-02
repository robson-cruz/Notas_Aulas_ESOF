/*
h. ​Listar o quanto cada cliente gastou em hospedagens
(status_hosp igual a “finalizada”),
em ordem decrescente por valor gasto.
*/
USE hospedar_db;

SELECT
	nome AS Cliente,
    SUM(Valor_total_hosp) AS 'Valor Hospedagem'
FROM Cliente
INNER JOIN Hospedagem ON Cliente.cliente_id = Hospedagem.cliente_id
WHERE status_hosp = 'finalizada'
GROUP BY nome
ORDER BY SUM(Valor_total_hosp) DESC;
