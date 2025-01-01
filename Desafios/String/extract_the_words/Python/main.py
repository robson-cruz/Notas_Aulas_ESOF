import re
from collections import Counter


def main():
    # Input string from the user
    input_string = input("Enter a string: ")

    # Use Regex to extract words - split by non-alphabetic characters
    word_pattern = re.split(r"[^A-Za-z]+", input_string)

    # Filter out empty strings and normalize case for word processing
    words = [word for word in word_pattern if word]  # All words (case-sensitive)
    normalized_words = [word.lower() for word in words]  # Words in lowercase

    # Count unique words and calculate word frequencies
    unique_words = set(normalized_words)  # Unique words (case-insensitive)
    word_frequencies = Counter([word.title() for word in normalized_words])  # Frequency with title case

    # Display results
    print(f"\nExtracted Words: {' '.join(words)}")
    print(f"Number of Words: {len(words)}")
    print(f"Number of unique Words: {len(unique_words)}")
    print("Word Frequencies:")
    for word, count in word_frequencies.items():
        print(f"{word}: {count}")


if __name__ == "__main__":
    main()
