from numerical_systems import decimal, binary

# Decimal to Binary
print(decimal.to_binary())

# Binary to Decimal
binary_number = 1001
decimal_number, calc = binary.to_decimal(binary_number)
print(f"The binary {binary_number} is {decimal_number} in decimal")
print(f"Steps of calculation:\n{calc}")
