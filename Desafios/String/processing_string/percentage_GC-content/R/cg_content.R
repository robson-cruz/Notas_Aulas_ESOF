#' Calculate the CG Content of a DNA Sequence
#'
#' @description
#'  The `cg_content` function computes the percentage of cytosine (`C`) and guanine (`G`) bases 
#' in a given DNA sequence. The input sequence can be provided either as a parameter or entered 
#' interactively. Non-DNA characters (`A`, `T`, `C`, `G`) in the input will trigger an error.
#'
#' @param input_string A character string representing a DNA sequence. If `NULL` (default), the 
#' function will prompt the user to input a DNA sequence via the console.
#'
#' @return A numeric value representing the CG content percentage in the DNA sequence.
#' 
#' @details The function converts the input DNA sequence to uppercase to ensure case insensitivity. 
#' It calculates the frequency of `C` and `G` bases in the sequence and computes the CG content 
#' as a percentage of the total sequence length. If the input contains invalid characters, an 
#' error is thrown.
#' 
#' @examples
#' # Calculate CG content for a given sequence
#' cg_content("acggtgttat") # Returns 40
#'
#' # Calculate CG content with user input
#' # Uncomment the line below to test interactively:
#' # cg_content()
#'
#' # Handle sequences with no CG content
#' cg_content("atatatat") # Returns 0
#'
#' # Invalid input will throw an error
#' # cg_content("xyz123") # Error: Invalid DNA sequence
#'
#' @export
cg_content <- function(input_string = NULL) {
    # If no input string is provided, prompt the user for input
    if (is.null(input_string)) {
        input_string <- readline(prompt = "Give a DNA sequence: ")
    }
    
    # Convert the input string to uppercase and split into characters
    string_vector <- unlist(strsplit(toupper(input_string), ""))
    
    # Validate that the string contains only DNA bases
    if (!all(string_vector %in% c("A", "T", "C", "G"))) {
        stop("Invalid DNA sequence. Only characters A, T, C, and G are allowed.")
    }
    
    # Create a frequency table for the characters
    string_table <- table(string_vector)
    
    # Ensure `C` and `G` are present in the table (default to 0 if absent)
    count_c <- ifelse("C" %in% names(string_table), string_table[["C"]], 0)
    count_g <- ifelse("G" %in% names(string_table), string_table[["G"]], 0)
    
    cg_percent <- (count_c + count_g) / length(string_vector) * 100
    
    # Return the CG content percentage
    return(cg_percent)
}


# Examples of calling the function
cat("CG content of 'acggtgttat': ", cg_content("acggtgttat"), "%\n", sep = "")
cat("CG content with user input:\n")
cg_content()
