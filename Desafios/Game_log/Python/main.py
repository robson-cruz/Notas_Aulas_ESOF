from random import sample


def secret_generator():
    """Generates a 4 digits secret code consisting of unique numbers

    Return:
        -- A String representing the 4-digits secret code with unique digits.
    """

    return ''.join(map(str, sample(range(10), 4)))


def count_bulls(secret_code, user_guess):
    """Checks the user's guess against the secret code and calculates the number Bulls

    Bulls: Digits in the user's guess that match both the value and position in the string secret_code.

    Arguments:
        secret_code -- String with 4-digits generate by the secret_generator() function.
        user_guess -- String representing the user's guess.

    Return values: an int representing the numbers of Bulls.
    """

    return sum(1 for i in range(len(secret_code)) if secret_code[i] == user_guess[i])


def count_cows(secret_code, user_guess):
    """Checks the user's guess against the secret code and calculates the number Cows

    Cows: Digits in the user's guess that exist in the string secret_code but are in the wrong position.

    Arguments:
        secret_code -- String with 4-digits generate by the secret_generator() function.
        user_guess -- String representing the user's guess.

    Return values: an int representing the numbers of Cows.
    """

    return sum(1 for i in range(len(secret_code)) if user_guess[i] in secret_code and user_guess[i] != secret_code[i])


def check_bulls_and_cows(bulls, cows, secret_code):
    """Generates feedback based on Bulls and Cows counts."""
    if bulls == 4:
        return f"Grade: {bulls} bulls.\nCongrats! The secret code is {secret_code}", True

    grade = []

    if bulls > 0:
        grade.append(f"{bulls} bull{'s' if bulls > 1 else ''}")
    if cows > 0:
        grade.append(f"{cows} cow{'s' if cows > 1 else ''}")

    return f"Grade: {' and '.join(grade) or 'None'}.", False


def start_game():
    """Main game loop."""
    attempts = 1
    secret_code = secret_generator()
    print("The secret code is prepared: ****.")

    is_secret_code_revealed = False
    while not is_secret_code_revealed:
        while True:
            user_guess = input(f"Turn {attempts}. Answer:\n")
            if user_guess.isdigit() and len(user_guess) == 4 and len(set(user_guess)) == 4:
                break
            print("Invalid input. Enter 4 unique digits.")

        bulls = count_bulls(secret_code, user_guess)
        cows = count_cows(secret_code, user_guess)
        feedback, is_secret_code_revealed = check_bulls_and_cows(bulls, cows, secret_code)
        print(feedback)
        attempts += 1


def main():
    start_game()


if __name__ == "__main__":
    main()
