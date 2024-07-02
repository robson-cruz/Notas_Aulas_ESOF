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
Buscar po produtos com um nome que come�am com "Volume" seguido por:

- um espa�o
- uma cadeia de caracteres
- um espa�o
- dois caracteres num�ricos
- um espa�o
- uma cadeia de caracteres
- um espa�o
- dois caracteres num�ricos
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
