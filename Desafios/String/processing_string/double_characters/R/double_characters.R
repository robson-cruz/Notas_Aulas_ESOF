double_character <- function(input) {
    input_split = strsplit(input, "")
    new_string = ""
    
    for (i in input_split) {
        new_string <- paste0(i, i, collapse = "")
    }
    
    return(new_string)
}


# Call the function
double_char <- double_character("The")
cat(double_char)
