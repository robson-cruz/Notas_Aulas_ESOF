#' Calcula a moda de um vetor de dados
#' 
#' @param x vetor
#' @return moda de um vetor
#' @author Robson Cruz



a <- c(2, 4, 5, 8, 11, 14, 21)
b <- c(2, 4, 5, 5, 8, 11, 14, 21)
c <- c(2, 4, 5, 5, 8, 11, 14, 21, 21)


moda <- function(x) {
        seen <- vector(mode = "logical", length = length(x))
        result <- vector(mode = "logical", length = length(x))
        for (i in seq_along(x)) {
                if (x[i] %in% x[seen]) {
                        result[i] <- TRUE
                }
                seen[i] <- TRUE
        }
        
        moda <- x[result]
        
        if (length(x[result]) == 0) {
                cat("\tNão existe moda, nenhum valor aparece com maior frequência, o vetor é amodal ou antimodal.")
        }
        else if (length(a[result]) == 1) {
                cat("\tA moda é ", moda)
        }
        else {
                cat("\tExiste mais de uma moda (", moda, ")", "portanto, o vetor é multimodal.", sep = " ")
        }
}

moda(a)
moda(b)
moda(c)
