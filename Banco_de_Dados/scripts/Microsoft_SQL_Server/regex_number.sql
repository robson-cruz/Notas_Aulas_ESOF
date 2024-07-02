USE AdventureWorks2022;
GO

SELECT TOP (100)
    SpecialOfferID
    , Description
    , DiscountPct
    , Type
    , Category
    , StartDate
    , EndDate
    , MinQty
    , MaxQty
FROM Sales.SpecialOffer;

/*
Buscar po produtos com um nome que começam com "Volume" seguido por:

- um espaço
- uma cadeia de caracteres
- um espaço
- dois caracteres numéricos
- um espaço
- uma cadeia de caracteres
- um espaço
- dois caracteres numéricos
*/
SELECT TOP (100)
	SpecialOfferID
    , Description
    , DiscountPct
    , Type
    , Category
    , StartDate
    , EndDate
    , MinQty
    , MaxQty
FROM Sales.SpecialOffer
WHERE Description LIKE 'Volume % [0-9][0-9] % [0-9][0-9]';
GO
