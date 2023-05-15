#' Calcula a mediana de um vetor de dados
#' 
#' @param x vetor
#' @return mediana de um vetor
#' @author Robson Cruz
#' @examples \dontrun{
#' a <- c(10, 3, 4, 8, 9, 2)    # 4
#' b <- c(3, 7, 9, 10, 4, 8, 2) # 7
#' mediana(a)
#' mediana(b)
#' }



mediana <- function(x) {
        x <- sort(x)
        if (length(x) %% 2 == 0) {
                after <- length(x)/2
                before <- after + 1
                
                return((x[(after + before) / 2]))
        }else{
                idx <- ceiling(length(x) / 2)
                return(x[idx])
        }
}
