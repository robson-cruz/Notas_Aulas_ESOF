SELECT name
FROM sys.database_principals
WHERE type IN ('S', 'U', 'G')
AND name NOT LIKE '##%'
ORDER BY name;
