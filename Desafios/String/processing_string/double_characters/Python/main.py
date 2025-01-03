def double_char(string=None):
    if string is None:
        string = input("Enter a string: ")

    new_string = [''.join(i*2) for i in string]

    return ''.join(new_string)


if __name__ == "__main__":
    my_double_char = double_char()
    print(my_double_char)
