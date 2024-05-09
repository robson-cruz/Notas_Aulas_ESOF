USE sakila;

-- Obter todas as visualizações que não são do sistema
SELECT * FROM INFORMATION_SCHEMA.VIEWS
WHERE TABLE_SCHEMA NOT IN ('sys', 'mysql'); -- Excluir visualizações do sistema nos resultados.
