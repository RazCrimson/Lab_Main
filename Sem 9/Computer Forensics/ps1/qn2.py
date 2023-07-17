import os
import requests
import hashlib

API_KEY = os.environ['API_KEY']

URL_PREFIX = "https://www.virustotal.com/api/v3/files"

headers = {
    "accept": "application/json",
    "content-type": "multipart/form-data",
    'x-apikey': API_KEY
}

def check_status(file_path: str) -> str:
    f= open(file_path, 'rb')
    contents = f.read()
    m = hashlib.sha256(contents)
    file_hash = m.hexdigest()
    url=f"{URL_PREFIX}/{file_hash}"

    response = requests.get(url, headers=headers)
    return response.text

if __name__ == '__main__':
    import sys 
    
    file_path = sys.argv[1]
    if os.path.isfile(file_path):
        resp = check_status(file_path)
        print(resp)
    else:
        print("Specified Path not a file")