/*
5. Efetue a criação dos seguintes procedimentos usando PL/MySQL:
b. Criar uma procedure chamada "CalcularTotalHospedagem" que aceita hospedagem_id como parâmetro.
A procedure deve calcular o valor total da hospedagem com base na diferença de dias entre check-in e
check-out e o preço da diária do quarto reservado. O valor deve ser atualizado na coluna valor_total_hosp.​
*/
USE hospedar_db;

DELIMITER $$
CREATE PROCEDURE CalcularTotalHospedagem(IN hosp_id INT)
BEGIN
    -- Total de dias hospedado
    DECLARE diarias INT;
    -- Valor da diária
    DECLARE custo_diaria FLOAT;
    -- Valor total a ser pago após check out
    DECLARE valor_total_hosp_final DECIMAL(10, 2);
    -- Data de entrada definitiva
    DECLARE dt_checkin_fato DATE;
    -- Data de saída definitiva
    DECLARE dt_checkout_fato DATE;
    -- Contador para id de hospedagem
    DECLARE conta_id_hosp INT;
    
    -- Confere se o id de hospedagem existe na tabela Hospedagem
    SELECT COUNT(*) INTO conta_id_hosp
    FROM Hospedagem WHERE hospedagem_id = hosp_id;
    
    IF conta_id_hosp = 1 THEN
        -- Desativa temporariamente o modo de atualização segura, caso esteja habilitado
        SET @@SESSION.sql_safe_updates = 0;
        
        SELECT
            preco_diaria,
            dt_checkin,
            dt_checkout
        INTO
            custo_diaria,
            dt_checkin_fato,
            dt_checkout_fato
        FROM Hospedagem
        INNER JOIN Quarto ON Hospedagem.quarto_id = Quarto.quarto_id
        WHERE Hospedagem.hospedagem_id = hosp_id;
        
        -- Cálculo da conta a ser paga pelo cliente
        SET diarias = DATEDIFF(dt_checkout_fato, dt_checkin_fato);
        SET valor_total_hosp_final = diarias * custo_diaria;
        
        -- Atualiza o valor total de hospedagem na tabela Hospedagem
        UPDATE Hospedagem
        SET valor_total_hosp = valor_total_hosp_final
        WHERE hospedagem_id = hosp_id;
        
        -- Ativa novamente o modo de atualização segura
        SET @@SESSION.sql_safe_updates = 1;
        
    ELSE
        SELECT CONCAT('ID de hospedagem ', hosp_id, ' não encontrado!') AS Error_Message;
    END IF;
    
END $$
DELIMITER ;
