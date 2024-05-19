import chardet
import json


def encoding_detect(csv_file_path):
    with open(csv_file_path, 'rb') as f:
        sample_data = chardet.detect(f.read(10000))  # Read the first 10kB from the csv file
    # return #sample_data['encoding']
    return sample_data


csv_file = 'dados_alunos.csv'
detected_encoding = encoding_detect(csv_file)
print(json.dumps(detected_encoding, indent=4))
