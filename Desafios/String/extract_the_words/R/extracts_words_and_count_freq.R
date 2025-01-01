string_clean <- function() {
    # Input string from the user
    input_string = readline(prompt = "Enter a string: ")
    
    # Clean input string using Regex to remove non-alphabetic characters
    cleaned_string <- gsub("\\s+$", "", gsub("[^A-Za-z]+", " ", input_string))
    
    # Split the string into words and normalize case
    words <- unlist(strsplit(cleaned_string, "\\s+"))  # Split by whitespace
    normalized_words <- R.utils::capitalize(words)  # Normalize to lowercase
    
    # Get the number of words
    number_of_words <- length(words)
    
    # Get unique words
    unique_words <- unique(normalized_words)
    
    # Calculate word frequencies
    # word_frequencies <- list()
    # 
    # # Iterate over each word in the vector normalized_words to count frequencies
    # for (word in normalized_words) {
    #     if (word %in% names(word_frequencies)) {
    #         word_frequencies[[word]] <- word_frequencies[[word]] + 1
    #     } else {
    #         word_frequencies[[word]] <- 1
    #     }
    # }
    word_frequencies <- table(normalized_words)
    
    # Display results
    cat(paste("\nExtracted Words:", cleaned_string))
    cat(paste("\nNumber of Words:",number_of_words))
    cat(paste("\nNumber of Unique Words:", length(unique_words)))
    cat("\nWord Frequencies:\n")
    for (word in names(word_frequencies)) {
        cat(sprintf("%s: %d\n", word, word_frequencies[word]))
    }
    
}


# Run the function
string_clean()
