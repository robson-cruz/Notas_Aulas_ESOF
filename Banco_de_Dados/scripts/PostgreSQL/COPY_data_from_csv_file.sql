COPY alunos(nome_aluno, email)
FROM 'dados_alunos.csv'
WITH
	DELIMITER ','
	CSV HEADER;
