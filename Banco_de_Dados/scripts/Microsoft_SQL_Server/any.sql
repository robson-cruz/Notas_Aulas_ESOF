USE ContosoRetailDW;

SELECT
	StoreKey, StoreName
FROM DimStore
WHERE StoreKey = ANY (
	SELECT StoreKey FROM FactSales
		WHERE DimStore.StoreKey = FactSales.StoreKey
			AND YEAR(DateKey) = '2008'
				AND SalesAmount >= 100000
);
