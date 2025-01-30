def zoo_keeper():
    zoo_dictionary = {
        "deer": "looks fine",
        "bat": "looks happy",
        "lion": "looks healthy"
    }

    print("I love animals!\nLet's check on the animals...")

    for key, value in zoo_dictionary.items():
        print(f"The {key} {value}.")


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    zoo_keeper()
