USE exercicios_constraints;


CREATE TABLE dim.Cliente(
	id_cliente INT IDENTITY(1, 1),
	nome_cliente VARCHAR(100) NOT NULL,
	genero VARCHAR(3) NOT NULL,
	data_nascimento DATE NOT NULL,
	cpf VARCHAR(11) NOT NULL,
	CONSTRAINT dcliente_id_cliente_pk PRIMARY KEY(id_cliente),
	CONSTRAINT dcliente_genero_ck CHECK(Genero IN ('M', 'F', 'O', 'PND')),
	CONSTRAINT dcliente_cpf_un UNIQUE(cpf)
);


INSERT INTO dim.cliente(nome_cliente, genero, data_nascimento, cpf)
VALUES
	('André Martins',  'M',  '12/02/1989', '839.283.190-00'),
	('Bárbara Campos',  'F', '07/05/1992', '351.391.410-02'),
	('Carol Freitas',  'F',  '23/04/1985', '139.274.921-12'),
	('Diego Cardoso',   'M', '11/10/1994', '192.371.081-17'),
	('Eduardo Pereira', 'M', '09/11/1988', '193.174.192-82'),
	('Fabiana Silva',  'F',  '02/09/1989', '231.298.471-98'),
	('Gustavo Barbosa', 'M', '27/06/1993', '240.174.171-76'),
	('Helen Viana',    'F',  '11/02/1990', '193.129.183-01'),
	('Igor Castro',    'M',  '21/08/1989', '184.148.102-29'),
	('Juliana Pires',   'F', '13/01/1991', '416.209.192-47');



-- Adiciona um comentário à coluna genero via procedure stored
EXEC sp_addextendedproperty 
    @name = N'Comentário', 
    @value = N'M = Masculino; F = Feminino; O = Outros; PND = Prefere não declarar.', 
    @level0type = N'SCHEMA', @level0name = 'dbo', 
    @level1type = N'TABLE',  @level1name = 'dCliente',
    @level2type = N'COLUMN', @level2name = 'genero';

-- Recuperar comentários de campos de uma tabela
SELECT 
    objname AS TableName,
    name AS PropertyName,
    value AS PropertyValue
FROM 
    fn_listextendedproperty (
        NULL, 
        'schema', 'dbo', 
        'table', 'dCliente', 
        'column', default
    );
