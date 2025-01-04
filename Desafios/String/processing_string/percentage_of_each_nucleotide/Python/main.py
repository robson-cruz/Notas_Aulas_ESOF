def nucleotide_percent(input_string=None):
    """Return the percentage of each nucleotide (A, C, G, T) in the sequence"""
    if input_string is None:
        input_string = input("Give me a DNA Sequence: ").upper()

    # Validate input to ensure it's a valid DNA sequence
    if not all(nucleotide in "ACGT" for nucleotide in input_string):
        print("Invalid DNA sequence. Please enter a sequence containing only A, C, G, and T.")
        return

    dna_dictionary = {}

    for nucleotide in input_string:
        dna_dictionary[nucleotide] = dna_dictionary.get(nucleotide, 0) + 1

    for key, value in dna_dictionary.items():
        percentage = value / len(input_string) * 100
        print(f'{key}: {percentage:.2f}%')


if __name__ == "__main__":
    nucleotide_percent()
