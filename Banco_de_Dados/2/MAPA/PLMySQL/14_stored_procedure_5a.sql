/*
5. Efetue a criação dos seguintes procedimentos usando PL/MySQL:
a. Criar uma procedure chamada "RegistrarCheckIn" que aceita hospedagem_id e data_checkin como parâmetros.
A procedure deve atualizar a data de check-in na tabela "Hospedagem" e mudar o status_hosp para "hospedado".​
*/
USE hospedar_db;

DELIMITER $$
CREATE PROCEDURE RegistrarCheckIn(IN hosp_id INT, IN data_checkin DATE)
BEGIN
	DECLARE conta_hospedagem_id INT;
    DECLARE status_hosp_novo VARCHAR(50);
    
    -- Confere se a hospedagem existe
    SELECT COUNT(*) INTO conta_hospedagem_id
    FROM Hospedagem WHERE hospedagem_id = hosp_id;
    
    IF conta_hospedagem_id = 1 THEN
        -- Desativa temporariamente o modo de atualização segura, caso esteja habilitado
        SET @@SESSION.sql_safe_updates = 0;
        
        -- Atualiza a tabela com a nova da ta de checkin
        BEGIN
			UPDATE Hospedagem
            SET dt_checkin = data_checkin, status_hosp = 'hospedado'
            WHERE hospedagem_id = hosp_id;
        END;
        
		-- Ativa novamente o modo de atualização segura
        SET @@SESSION.sql_safe_updates = 1;
        
	ELSE
		SELECT CONCAT('Id de Hospedagem ', hosp_id, ' não encontrado!') AS Error_Message;
    END IF;
END $$
DELIMITER ;;
