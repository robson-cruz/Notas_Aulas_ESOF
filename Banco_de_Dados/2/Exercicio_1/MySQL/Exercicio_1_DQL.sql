USE mae_bebe;

SELECT * FROM cidade WHERE id_estado = 5;

SELECT
	crm_medico,
    medico.nome AS medico,
    bebe.nome,
    bebe.data_nascimento,
    mae.nome AS mae
FROM bebe
INNER JOIN mae ON bebe.id_mae = mae.id
INNER JOIN medico ON bebe.crm_medico = medico.crm;

