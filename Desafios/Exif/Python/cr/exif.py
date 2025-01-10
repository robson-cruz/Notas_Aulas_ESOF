import os
import exifread
import pandas as pd


def convert_to_decimal(degrees, minutes, seconds, direction):
    """Convert GPS coordinates to decimal degree format."""
    decimal = degrees + (minutes / 60.0) + (seconds / 3600.0)
    if direction in ['S', 'W']:
        decimal = -decimal

    return decimal


def extract_metadata(file_path):
    """Extract relevant metadata from a CR2 file"""
    google_maps_url = "https://www.google.com/maps?q="

    with open(file_path, "rb") as img_file:
        # Read Exif data from each file
        tags = exifread.process_file(img_file)

        metadata = {
            'Filename': os.path.basename(file_path),
            'DateTimeOriginal': str(tags.get('Image DateTime', None)),
            'FNumber': str(tags.get('EXIF FNumber', None)),
            'ExposureTime': str(tags.get('EXIF ExposureTime', None)),
            'ISOSpeedRatings': str(tags.get('EXIF ISOSpeedRatings', None)),
            'CameraModel': str(tags.get('Image Model', None)),
            'LensModel': str(tags.get('EXIF LensModel', None)),
            'Latitude': None,
            'Longitude': None,
            'Google Map Link': None,
        }

        # Extract GPS data if available
        if 'GPS GPSLatitude' in tags and 'GPS GPSLongitude' in tags:
            lat = tags['GPS GPSLatitude'].values
            lat_ref = str(tags.get('GPS GPSLatitudeRef', None))
            lon = tags['GPS GPSLongitude'].values
            lon_ref = str(tags.get('GPS GPSLongitudeRef', None))

            metadata['Latitude'] = convert_to_decimal(float(lat[0]), float(lat[1]), float(lat[1]), lat_ref)
            metadata['Longitude'] = convert_to_decimal(float(lon[0]), float(lon[1]), float(lon[1]), lon_ref)
            metadata['Google Map Link'] = f"{google_maps_url}{metadata['Latitude']},{metadata['Longitude']}"

        return metadata


def process_directory(input_directory):
    """Process all CR2 files in a directory"""
    metadata_list = []
    for file in os.listdir(input_directory):
        if file.lower().endswith(".cr2"):
            filepath = os.path.join(input_directory, file)
            metadata = extract_metadata(filepath)
            metadata_list.append(metadata)

    # Create DataFrame
    dataframe = pd.DataFrame(metadata_list)

    return dataframe


def organize_directory(input_directory):
    """Organize CR2 files into subdirectories by year."""
    for file in os.listdir(input_directory):
        if file.lower().endswith(".cr2"):
            filepath = os.path.join(input_directory, file)
            metadata = extract_metadata(filepath)

            # Extract the year from DateTimeOriginal
            date_time = str(metadata.get('DateTimeOriginal', None))
            if date_time:
                year = date_time.split(':')[0]
                new_folder = os.path.join(input_directory, year)

                # Create the subdirectory if it doesn't exist
                os.makedirs(new_folder, exist_ok=True)

                # Move the file to the corresponding subdirectory
                source = os.path.join(input_directory, file)
                dest = os.path.join(new_folder, file)

                try:
                    os.rename(source, dest)
                except FileExistsError:
                    print(f"File '{file}' already exists in '{new_folder}'. Skipping.")
