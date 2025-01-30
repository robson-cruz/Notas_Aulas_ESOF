# Matrix
m <- matrix(1:9, nrow = 3)

# Keeps the data structure
apply(m, 1, function(x) x %% 2 == 0)

# Convert the the input data structuire into a vector
my_vec <- sapply(m, function(x) x %% 2 == 0)

# Convert the the input data structuire into a list
my_list <- lapply(m, function(x) if (x %% 2 == 0) "even" else "odd")

# Choose the output
vapply(m, function(x) x %% 2 == 0, logical(1))
vapply(m, function(x) x %% 2 == 0, numeric(1))
vapply(m, function(x) if (x %% 2 == 0) "even" else "odd", character(1))
