USE ContosoRetailDW;

-- Get all non-systems views
SELECT * FROM INFORMATION_SCHEMA.VIEWS
WHERE table_schema NOT IN ('pg_catalog', 'information_schema'); --Exclude system views in the results.
