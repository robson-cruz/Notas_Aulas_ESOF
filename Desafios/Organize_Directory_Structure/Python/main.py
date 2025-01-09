import os
import json


def organize_files(directory=None):
    """
    This function takes a directory containing files of various types (e.g., .txt, .jpg, .py, .pdf), organize them into
    subdirectories based on their file extensions.

    :param directory:
    """
    if directory is None:
        directory = input("Give me the directory: ")

    # Check if the directory exists
    if not os.path.exists(directory):
        print(f"The directory '{directory}' does not exists!")
        return

    # get the contents of the directory
    list_of_files = os.listdir(directory)

    # Split file and its extension and make a dictionary where the directory is the key and the extension is the value
    file_dictionary = {
        os.path.splitext(i)[0]: os.path.splitext(i)[1].replace('.', '') for i in list_of_files if not os.path.isdir(i)
    }

    # Create a directory for each file extension  and Move each file to its respective directory
    for file, ext in file_dictionary.items():
        try:
            os.mkdir(f"{directory}/{ext}")
        except FileExistsError:
            pass
        os.rename(f"{directory}/{file}.{ext}", f"{directory}/{ext}/{file}.{ext}")

    # Summary file data
    summary_data = {}
    for file, ext in file_dictionary.items():
        if ext:
            summary_data[ext] = summary_data.get(ext, 0) + 1

    print(json.dumps(summary_data, indent=4))


if __name__ == "__main__":
    organize_files()
