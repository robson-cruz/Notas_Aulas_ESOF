-- Conectar ao banco de dados com um usuário administrador
USE AlugaFacil;
GO

-- Revogar privilégios do usuário
REVOKE CONNECT FROM crazy_usr;
-- Outros privilégios podem ser revogados conforme necessário

-- Declarar variáveis
DECLARE @sql NVARCHAR(MAX);
DECLARE @table NVARCHAR(128);
DECLARE @view NVARCHAR(128);

-- Remover tabelas pertencentes ao usuário
DECLARE table_cursor CURSOR FOR
SELECT name
FROM sys.tables
WHERE schema_id = SCHEMA_ID('dbo') AND principal_id = DATABASE_PRINCIPAL_ID('crazy_usr');

OPEN table_cursor;
FETCH NEXT FROM table_cursor INTO @table;

WHILE @@FETCH_STATUS = 0
BEGIN
    SET @sql = 'DROP TABLE dbo.' + QUOTENAME(@table);
    EXEC sp_executesql @sql;
    FETCH NEXT FROM table_cursor INTO @table;
END

CLOSE table_cursor;
DEALLOCATE table_cursor;

-- Remover views pertencentes ao usuário
DECLARE view_cursor CURSOR FOR
SELECT name
FROM sys.views
WHERE schema_id = SCHEMA_ID('dbo') AND principal_id = DATABASE_PRINCIPAL_ID('crazy_usr');

OPEN view_cursor;
FETCH NEXT FROM view_cursor INTO @view;

WHILE @@FETCH_STATUS = 0
BEGIN
    SET @sql = 'DROP VIEW dbo.' + QUOTENAME(@view);
    EXEC sp_executesql @sql;
    FETCH NEXT FROM view_cursor INTO @view;
END

CLOSE view_cursor;
DEALLOCATE view_cursor;

-- Finalmente, excluir o usuário
DROP USER crazy_usr;
GO
