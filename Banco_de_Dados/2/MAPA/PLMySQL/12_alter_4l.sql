/*
l. ​Criar a coluna checkin_realizado do tipo booleano na tabela Hospedagem (via código).
E atribuir verdadeiro para as Hospedagens com status_hosp “finalizada” e “hospedado”,
e como falso para Hospedagens com status_hosp “reserva” e “cancelada”.
*/
USE hospedar_db;

ALTER TABLE Hospedagem ADD COLUMN checkin_realizado BOOLEAN;


UPDATE Hospedagem
SET checkin_realizado = TRUE
WHERE status_hosp IN ('finalizada', 'hospedado') AND hospedagem_id IS NOT NULL AND hospedagem_id > 0;

UPDATE Hospedagem
SET checkin_realizado = FALSE
WHERE status_hosp IN ('reserva', 'cancelada') AND hospedagem_id IS NOT NULL AND hospedagem_id > 0;
