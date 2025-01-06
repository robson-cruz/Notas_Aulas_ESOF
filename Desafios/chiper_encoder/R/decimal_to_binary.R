#' Convert Decimal Number to Binary
#'
#' This function converts a decimal number to its binary representation.
#' It either takes an input directly as an argument or prompts the user to input a number.
#'
#' @param decimal_number Numeric. A decimal number to convert to binary. If not provided, 
#' the function will prompt the user for input.
#'
#' @return A character string representing the binary equivalent of the input decimal number.
#'
#' @examples
#' # Example 1: Provide input directly
#' decimal_to_binary(10)
#' # Returns: "1010"
#'
#' # Example 2: Prompt for user input
#' \dontrun{
#' decimal_to_binary()
#' }
#'
#' @export
decimal_to_binary <- function(decimal_number = NULL) {
    if (is.null(decimal_number)) 
        decimal_number <- as.numeric(readline(prompt = "Enter decimal number: "))
    
    binary <- ""
    
    while (decimal_number != 0) {
        binary <- paste0(decimal_number %% 2, binary)
        decimal_number <- decimal_number %/% 2
    }
    
    return(binary)
}


# Run the function
decimal_to_binary()
