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

    # Filter files and skip directories
    file_dictionary = {
        file: os.path.splitext(file)[1].lstrip(".")
        for file in list_of_files
        if os.path.isfile(os.path.join(directory, file))
    }

    # Create a directory for each file extension and move files
    for file, ext in file_dictionary.items():
        if not ext:  # Skip files without extension
            continue

        # Create the subdirectory for the extension if it doesn't exist
        new_folder = os.path.join(directory, ext)
        try:
            os.mkdir(new_folder)
        except FileExistsError:
            pass

        # Move the file to the corresponding subdirectory
        source = os.path.join(directory, file)
        dest = os.path.join(new_folder, file)
        try:
            os.rename(source, dest)
        except FileExistsError:
            print(f"File '{file}' already exists in '{new_folder}'. Skipping.")

    # Generate summary data
    summary_data = {}
    for ext in file_dictionary.values():
        if ext:  # Count only files with extensions
            summary_data[ext] = summary_data.get(ext, 0) + 1

    # Print summary as JSON
    print(json.dumps(summary_data, indent=4, sort_keys=True))


if __name__ == "__main__":
    organize_files()
