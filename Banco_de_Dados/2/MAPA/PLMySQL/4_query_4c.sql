/*
c. ​Mostrar o histórico de hospedagens em ordem cronológica de um determinado cliente;
*/
USE hospedar_db;

SELECT
	nome AS Cliente,
    dt_checkin AS 'Check In',
    dt_checkout AS 'Check Out'
FROM Cliente
INNER JOIN Hospedagem ON Cliente.cliente_id = Hospedagem.cliente_id
WHERE nome = 'Antonio Zimermax'
ORDER BY dt_checkin;
