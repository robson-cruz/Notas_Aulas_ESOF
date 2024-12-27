word = "Massaranduba"

number_of_letters = list()

for (char in strsplit(word, "")[[1]]) {
    if (char %in% names(number_of_letters)) {
        number_of_letters[char] <- number_of_letters[[char]] + 1
    } else {
        number_of_letters[char] <- 1
    }
}
