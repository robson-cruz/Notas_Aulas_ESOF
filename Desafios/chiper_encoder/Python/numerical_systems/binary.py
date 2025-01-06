def to_decimal(binary=None):
    if binary is None:
        binary = int(input("Enter binary number: "))
    binary_string = str(binary)

    decimal = 0
    steps_expression = []

    for i in range(len(binary_string)):
        decimal += int(binary_string[i]) * 2 ** (len(binary_string) - (i + 1))
        steps_expression.append(f"{binary_string[i]}.2**{len(binary_string) - (i + 1)}")

    return decimal, f"{' + '.join(steps_expression)} = {decimal}"


if __name__ == "__main__":
    to_decimal()
