USE clinica_vet;

ALTER TABLE consulta
	MODIFY horario TIME
		COMMENT 'Registrar horário no formato 24h: hh:mm. Exemplo: 13:30';
