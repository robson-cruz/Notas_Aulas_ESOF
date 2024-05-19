CREATE TABLE alunos(
    id_aluno NUMBER(6,0) PRIMARY KEY,
	nome_aluno VARCHAR2(50 BYTE) NOT NULL,
	email VARCHAR2(50 BYTE) NOT NULL
);


INSERT ALL
    INTO alunos(id_aluno, nome_aluno, email)
    VALUES(1, 'Anna Banzer', 'anna12@gmail.com')
    INTO alunos(id_aluno, nome_aluno, email)
    VALUES(2, 'Robert Fronz', 'rfr34@hotmail.com')
    INTO alunos(id_aluno, nome_aluno, email)
    VALUES(3, 'Albert Yoziff', 'yosiff.alber@yahoo.com')
    INTO alunos(id_aluno, nome_aluno, email)
    VALUES(4, 'Rob williams', 'wrob43@hotmail.com')
SELECT * FROM dual;
