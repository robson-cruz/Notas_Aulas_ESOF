-- Primeiro, exclua a função existente
DROP FUNCTION IF EXISTS fn_stock_control();

-- Agora, crie a nova função com o tipo de retorno VOID e a lógica para criar a tabela
CREATE OR REPLACE FUNCTION fn_stock_control()
    RETURNS VOID
    LANGUAGE plpgsql
AS
$$
BEGIN
    -- Verificar se a tabela temporária já existe
    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE tablename = 'low_stock_products') THEN
        -- Se não existir, criar a tabela temporária com os produtos com estoque baixo
        CREATE TEMPORARY TABLE low_stock_products AS
        SELECT product_id, product_name, units_in_stock
        FROM products
        WHERE units_in_stock <= 5;

        -- Se desejar, pode fazer algo com a tabela criada, como exibir ou processar mais dados
        -- Exemplo: SELECT * FROM low_stock_products;
        -- SELECT * FROM low_stock_products;
		SELECT * FROM low_stock_products;
    END IF;

    -- Você também pode adicionar índices ou executar outras operações aqui

    -- Se não precisar fazer mais nada, pode apenas encerrar a função
END 
$$;
