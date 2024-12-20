from functools import lru_cache


@lru_cache(None)
def fibonacci(number):
    if number == 0 or number == 1:
        return number
    else:
        return fibonacci(number - 1) + fibonacci(number - 2)


# Solicitar ao usuário um número
n = int(input("Diite um número: "))

# Calcular e exibir o resultado
print(f"O número Fibonacci na posição {n} é: {fibonacci(n)}")
