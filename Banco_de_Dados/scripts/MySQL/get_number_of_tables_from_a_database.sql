USE sakila;

SELECT COUNT(*) AS Num_Of_Columns
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'film';
