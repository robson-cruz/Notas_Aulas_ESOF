SET SERVEROUTPUT ON;

DECLARE
    r NUMBER;
    PI NUMBER;
    area NUMBER;
BEGIN
    PI := 3.141592654;
    r := 2;
    area := PI * POWER(r, 2);
    DBMS_OUTPUT.PUT_LINE('Area: ' || area);
END;
