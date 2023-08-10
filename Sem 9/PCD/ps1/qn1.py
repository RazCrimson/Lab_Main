import requests


INDEX_URL = 'index.php'
session = requests.Session()
session.get('https://psgtech.edu/')
res = session.get(INDEX_URL, verify=False)
print(res.text)
