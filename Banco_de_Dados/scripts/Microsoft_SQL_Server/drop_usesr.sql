-- Conectar ao banco de dados com um usu�rio administrador
USE AlugaFacil;
GO

-- Revogar privil�gios do usu�rio
REVOKE CONNECT FROM crazy_usr;
-- Outros privil�gios podem ser revogados conforme necess�rio

-- Declarar vari�veis
DECLARE @sql NVARCHAR(MAX);
DECLARE @table NVARCHAR(128);
DECLARE @view NVARCHAR(128);

-- Remover tabelas pertencentes ao usu�rio
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

-- Remover views pertencentes ao usu�rio
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

-- Finalmente, excluir o usu�rio
DROP USER crazy_usr;
GO
