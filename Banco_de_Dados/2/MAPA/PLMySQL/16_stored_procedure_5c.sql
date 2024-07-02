/*
5. Efetue a criação dos seguintes procedimentos usando PL/MySQL:
c. Criar uma procedure chamada "RegistrarCheckout" que aceita hospedagem_id e
data_checkout como parâmetros.

A procedure deve atualizar a data de check-out na tabela "Hospedagem" e mudar o status_hosp para "finalizada".​
*/
USE hospedar_db;

DELIMITER $$
CREATE PROCEDURE RegistrarCheckout(IN hosp_id INT, IN data_checkout DATE)
BEGIN
	DECLARE conta_hospedagem_id INT;
	
    -- Conferir se a hospedagem é válida
    SELECT COUNT(*) INTO conta_hospedagem_id
    FROM Hospedagem
    WHERE hospedagem_id = hosp_id;
    
    IF conta_hospedagem_id = 1 THEN
        -- Desativa temporariamente o modo de atualização segura, caso esteja habilitado
        SET @@SESSION.sql_safe_updates = 0;
        
        -- Atualiza a tabela Hospedagem com a data de check out
        BEGIN
			UPDATE Hospedagem
            SET dt_checkout = data_checkout, status_hosp = 'finalizada'
            WHERE hospedagem_id = hosp_id;
        END;
        
        -- Ativa novamente o modo de atualização segura
        SET @@SESSION.sql_safe_updates = 1;
    ELSE
		SELECT CONCAT('Id de Hospedagem ', hosp_id, ' não encontrado!') AS Error_Message;
    END IF;
END $$
DELIMITER ;
