fibonacci <- local({
    # Ambiente para armazenar valores já calculados
    cache <- new.env()
    
    function(number) {
        if (exists(as.character(number), envir = cache)) {
            # Retorna o valor do cache se já calculado
            return(get(as.character(number), envir = cache))
        }
        
        # Calcular o valor de Fibonacci
        result <- if (number == 0 | number == 1) {
            number
        } else {
            fibonacci(number - 1) + fibonacci(number - 2)
        }
        
        # Armaneza o valor no cache
        assign(as.character(number), result, envir = cache)
        return(result)
    }
})


# Solicitar um número ao usuário
cat("Digite um número: ")
n <- as.integer(readline())

# Calcular e exibir o resultado
cat(paste("O número Fibonacci na posição", n, "é:", fibonacci(n), "\n"))
