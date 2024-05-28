USE mae_bebe;

-- 1. Adicione uma coluna email do tipo VARCHAR(100) à tabela mae.
ALTER TABLE mae
	ADD COLUMN email VARCHAR(100);

-- 2. Adicione uma coluna data_cadastro do tipo DATE à tabela medico.
ALTER TABLE medico
	ADD COLUMN data_cadastro DATE;
    
-- 3. Adicione uma coluna observacao do tipo TEXT à tabela bebe.
ALTER TABLE bebe
	ADD COLUMN observacao TEXT;
    
-- 4. Altere o tamanho da coluna nome da tabela estado para VARCHAR(100).
ALTER TABLE estado
	MODIFY COLUMN nome VARCHAR(100);

-- 5. Defina a coluna celular na tabela medico como NOT NULL.
ALTER TABLE medico
	MODIFY COLUMN celular VARCHAR(15) NOT NULL;
    
-- 6. Renomeie a coluna ponto_referencia na tabela endereco para referencia.
ALTER TABLE endereco
	RENAME COLUMN ponto_referencia TO referencia;

-- 7. Renomeie a coluna altura na tabela bebe para comprimento (em centímetros).
ALTER TABLE bebe
	RENAME COLUMN altura TO comprimento;
    
/*** Adiciona uma comentário ao atributo 'altura' ***/
ALTER TABLE bebe
	MODIFY altura TINYINT COMMENT 'ALTURA DO BEBÊ EM CENTÍMETROS';

-- 8. Remova a coluna complemento da tabela endereco.
ALTER TABLE endereco
	DROP COLUMN complemento;

-- 9. Adicione uma restrição UNIQUE à coluna email da tabela mae.
ALTER TABLE mae
	MODIFY COLUMN email VARCHAR(100) UNIQUE;
