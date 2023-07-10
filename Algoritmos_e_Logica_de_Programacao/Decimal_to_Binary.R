decimal_to_binary <- function(x) {
        cont <- TRUE
        int <- c()
        resto <- c()
        
        while (cont) {
                resto <- append(x %% 2, resto)
                int <- append(x %/% 2, int)
                
                x <- x %/% 2
                
                cont <- x != 0
        }
        
        return(cat(resto))
}

decimal_to_binary(13) # 1101
decimal_to_binary(12) # 1100
