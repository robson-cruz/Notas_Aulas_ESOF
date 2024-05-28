-- Create the customer table
CREATE TABLE customer (
    id NUMBER(10) NOT NULL,
    name VARCHAR2(100) NOT NULL,
    gender VARCHAR2(3) NOT NULL
);

-- Add a comment to the gender column
COMMENT ON COLUMN customer.gender IS 'M = Male; F = Female; O = Others; DNA = Did Not Answer';

-- Create a sequence for the id column
CREATE SEQUENCE customer_seq START WITH 1;

-- Create a trigger to automatically assign the next value of the sequence to the id column
CREATE OR REPLACE TRIGGER customer_seq_trigger
BEFORE INSERT ON customer
FOR EACH ROW
BEGIN
    SELECT customer_seq.NEXTVAL
    INTO :new.id
    FROM dual;
END;
/
