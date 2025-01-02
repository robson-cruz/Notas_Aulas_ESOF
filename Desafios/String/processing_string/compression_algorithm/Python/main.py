def compression_string(input_string=None):
    """Compresses a string by replacing consecutive characters with the character followed by its count.

    Arguments:
        -- input_string (str): The string to be compressed.

    Returns:
        str: The compressed string.
    """
    if input_string is None:
        input_string = input("Give a sequence: ")

    output_string = []
    count = 1

    # Iterate through the string, starting from the second character
    for i in range(1, len(input_string)):
        if input_string[i] == input_string[i - 1]:
            count += 1
        else:
            # Append the previous character and its count
            output_string.append(input_string[i - 1])
            output_string.append(str(count))
            count = 1

    # Append the last character and its count
    output_string.append(input_string[len(input_string) - 1])
    output_string.append(str(count))

    # Join the list into a string and return
    return ''.join(output_string)


if __name__ == "__main__":
    compressed = compression_string()
    print(compressed)
