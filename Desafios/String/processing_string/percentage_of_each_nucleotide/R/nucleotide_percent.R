#' Calculate the Percentage of Each Nucleotide in a DNA Sequence
#'
#' This function calculates the percentage composition of each nucleotide 
#' (`A`, `C`, `G`, `T`) in a given DNA sequence. The input can either be 
#' provided as a string or entered interactively.
#'
#' @param input_string A character string representing a DNA sequence. If `NULL` 
#' (default), the function will prompt the user to input a DNA sequence via the console.
#'
#' @return A formatted output displaying the percentage composition of each 
#' nucleotide in the DNA sequence. Each percentage is rounded to two decimal places.
#'
#' @details The input DNA sequence is validated to ensure it contains only valid 
#' nucleotide characters (`A`, `C`, `G`, and `T`). Any invalid characters will 
#' trigger an error. The function calculates the percentage of each nucleotide 
#' relative to the total length of the sequence.
#'
#' @examples
#' # Calculate nucleotide percentages for a given sequence
#' nucleotide_percent("ATCGCGATCGATCGATCG")
#'
#' # Calculate nucleotide percentages with user input
#' # Uncomment the line below to test interactively:
#' # nucleotide_percent()
#'
#' # Example with a sequence containing no specific base
#' nucleotide_percent("AAAAAATTTTT") # A: 50%, T: 50%, C: 0%, G: 0%
#'
#' # Invalid input will throw an error
#' # nucleotide_percent("XYZ123") # Error: Invalid DNA sequence
#'
#' @export
nucleotide_percent <- function(input_string = NULL) {
    # If no input string is provided, prompt the user for input
    if (is.null(input_string)) {
        input_string <- readline(prompt = "Enter a DNA sequence: ")
    }
    
    # Convert the input string to uppercase and split into characters
    vector_string <- unlist(strsplit(gsub("\\s+", "", toupper(input_string)), ""))
    
    # Validate that the string contains only DNA bases
    if (!all(vector_string %in% c('A', 'C', 'G', 'T'))) {
        stop("Invalid DNA sequence. Only characters A, T, C, and G are allowed.")
    }
    
    # Create a frequency table for the characters
    bases_table <- table(vector_string)
    
    # Ensure `A`, `C`, `G` and `T` are present in the table (default to 0 if absent)
    a <- ifelse('A' %in% names(bases_table), bases_table[['A']], 0) / length(vector_string)
    c <- ifelse('C' %in% names(bases_table), bases_table[['C']], 0) / length(vector_string)
    g <- ifelse('G' %in% names(bases_table), bases_table[['G']], 0) / length(vector_string)
    t <- ifelse('T' %in% names(bases_table), bases_table[['T']], 0) / length(vector_string)
    
    # Build a data frame from the table
    df <- data.frame(
        base = c("A", "C", "G", "T"),
        percent = c(a, c, g, t)
    )
    
    # Format and return the results
    output <- glue::glue_data(df, "{base}: {sprintf('%.2f', percent * 100)}%")
    
    return(output)
}


# Run the function
nucleotide_percent("ATCGCGATCGATCGATCG")
nucleotide_percent()


