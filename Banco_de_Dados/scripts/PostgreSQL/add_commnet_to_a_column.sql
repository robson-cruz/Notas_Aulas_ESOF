CREATE TABLE customer (
	id SERIAL PRIMARY KEY,
	name VARCHAR(100) NOT NULL,
	gender VARCHAR(3) NOT NULL
);

COMMENT ON COLUMN customer.gender IS 'M = Male; F = Female; O = Other; DNA = Did Not Answer';