#' Compress a String by Counting Consecutive Characters
#'
#' The `string_compression` function takes a string as input and compresses it 
#' by replacing consecutive repeated characters with the character followed by 
#' the count of repetitions. For example, the string `"aaabbcc"` will be compressed 
#' to `"a3b2c2"`.
#'
#' @param input_string A character string to be compressed. The string should not be empty.
#'
#' @return A compressed version of the input string as a single character string.
#' 
#' @examples
#' # Compress a string with repeated characters
#' string_compression("aaaabbcaa") # Returns "a3b2c2"
#'
#' # Compress a string with no repeated characters
#' string_compression("aaaabbcaa") # Returns "a4b2c1a2"
#'
#' # Compress an empty string (returns an error message)
#' string_compression("") # Returns "String should has more then one character!"
#'
#' @export
string_compression <- function(input_string) {
    
    # Split the input string into a vector
    vector_of_char <- unlist(strsplit(input_string, ""))
    
    if (length(vector_of_char) < 2) {
        stop("String should has more then one charactere!")
    }
    
    count <- 1
    short_string <- ""
    
    # Iterate over each character of the vector
    for (i in 1:(length(vector_of_char) - 1)) {
        if (vector_of_char[i] == vector_of_char[i + 1]) {
            count <- count + 1
        } else {
            short_string <- paste0(short_string, vector_of_char[i], count)
            count <- 1
        }
    }
    
    # Add the last character and its count
    # Add the last character and its count
    if (length(vector_of_char) > 0) {
        short_string <- paste0(short_string, vector_of_char[length(vector_of_char)], count)
    }
    
    return(short_string)
}


# Run the function
compressed_string <- string_compression("")
cat("Compressed string:", compressed_string)
