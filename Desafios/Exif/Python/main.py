from cr import exif

# Directory containing CR2 files
directory = "img"

# Process the directory and extract metadata
df = exif.process_directory(directory)

# Save to csv
output_file = "../image_metadata.csv"
df.to_csv(output_file, index=False)

print(f"Metadata extracted and saved to {output_file}")

# Organize the directory
exif.organize_directory(directory)
