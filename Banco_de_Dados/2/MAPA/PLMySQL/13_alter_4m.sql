/*
m. ​Mudar o nome da coluna “classificacao” da tabela Hotel para “rating” (via código).
*/
USE hospedar_db;

ALTER TABLE Hotel
RENAME COLUMN classificacao TO rating;
