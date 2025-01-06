def to_binary(number=None):
    if number is None:
        number = int(input("Enter decimal number: "))

    binary = []

    while number != 0:
        binary.append(number % 2)
        number = number // 2

    return ''.join(str(i) for i in binary[::-1])


if __name__ == "__main__":
    to_binary()
