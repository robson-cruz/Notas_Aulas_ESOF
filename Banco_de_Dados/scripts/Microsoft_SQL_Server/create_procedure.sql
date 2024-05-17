-- Procedure to add a new customer in 'contas' table
CREATE PROCEDURE add_customer
@new_customer AS VARCHAR(100),
@value_to_add AS DECIMAL(18, 2)

AS
BEGIN
    -- Start an Explicit Transaction
    BEGIN TRANSACTION;

    BEGIN TRY
        -- Validations
        IF @new_customer IS NULL OR @new_customer = ''
        BEGIN
            RAISERROR('Customer name cannot be NULL or empty', 16, 1);
            RETURN;
        END
        
        IF @value_to_add < 0
        BEGIN
            RAISERROR('Initial balance cannot be negative', 16, 1);
            RETURN;
        END

        -- Data Insertion
        INSERT INTO contas (nome, saldo)
        VALUES (@new_customer, @value_to_add);

        -- Commit the the transaction if all was successfull
        COMMIT TRANSACTION;

        -- Optional Success Message
        PRINT 'Customer added successfully';
    END TRY
    BEGIN CATCH
        -- Rollback the trasaction if occurs any issue
        ROLLBACK TRANSACTION;

        -- Catch and show error message
        DECLARE @ErrorMessage NVARCHAR(4000);
        DECLARE @ErrorSeverity INT;
        DECLARE @ErrorState INT;

        SELECT
            @ErrorMessage = ERROR_MESSAGE(),
            @ErrorSeverity = ERROR_SEVERITY(),
            @ErrorState = ERROR_STATE();

        RAISERROR (@ErrorMessage, @ErrorSeverity, @ErrorState);
    END CATCH
END;
