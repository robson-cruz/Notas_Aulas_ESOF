import json

string_input = input("Enter a word: ").lower()
vowels = ['a', 'e', 'i', 'o', 'u', 'á', 'é', 'í', 'ó', 'ú', 'à', 'è', 'ì', 'ò', 'ù', 'ã', 'õ', 'â', 'ê', 'î', 'ô', 'û']

letters = {
    'string': string_input,
    'vowels': list({char for char in string_input if char in vowels}),
    'consonants': list({char for char in string_input if char not in vowels}),
    'n_letters': len(string_input),
    'n_vowels': len([char for char in string_input if char in vowels]),
    'n_consonants': len([char for char in string_input if char not in vowels])
}

print(json.dumps(letters, indent=4, ensure_ascii=False))
