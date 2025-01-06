#' Convert Binary Number to Decimal
#'
#' This function converts a binary number (as a string or numeric) to its decimal equivalent.
#' It validates the input, computes the decimal value, and displays the calculation steps.
#'
#' @param binary Character or numeric. A binary number to be converted. The input should contain only `0` and `1`. 
#' If the input is invalid, an error will be thrown.
#'
#' @return Numeric. The decimal equivalent of the binary input.
#' The function also prints the step-by-step conversion process.
#'
#' @examples
#' # Example 1: Valid binary input
#' binary_to_decimal(1001)
#' # Output: "1.2^3 + 0.2^2 + 0.2^1 + 1.2^0 = 9"
#' # Returns: 9
#'
#' # Example 2: Invalid binary input
#' \dontrun{
#' binary_to_decimal("10A1")
#' # Error: "Input contains non-binary digits. Please provide a valid binary number."
#' }
#'
#' @export
binary_to_decimal <- function(binary) {
    if (is.null(binary) || binary == "" || is.na(binary)) {
        return(NA)  # Return NA for invalid input
    }
    
    string_binary <- unlist(strsplit(as.character(binary), ""))
    
    # Validate binary input (ensure it only contains 0s and 1s)
    if (!all(string_binary %in% c("0", "1"))) {
        stop("Input contains non-binary digits. Please provide a valid binary number.")
    }
    
    decimal <- 0
    steps <- ""
    
    for (i in seq_along(string_binary)) {
        digit <- as.numeric(string_binary[i])
        exponent <- length(string_binary) - i
        decimal <- decimal + (digit * 2^exponent)  # Use correct exponentiation operator
        if (i < length(string_binary)) {
            steps <- paste0(steps, digit, ".2^", exponent, " + ")
        } else {
            steps <- paste0(steps, digit, ".2^", exponent)
        }
    }
    
    # Print steps and result
    cat(paste(steps, "=", decimal, "\n\n"))
    return(decimal)
}

# Run the function
binary_to_decimal(1001)
binary_to_decimal(1001)[1]


# Run the function
binary_to_decimal(1008)
